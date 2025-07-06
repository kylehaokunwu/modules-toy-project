import os
import sys
import re

def header_to_partition_name(header_path):
    """Convert header path to module partition name."""
    # Get just the filename without extension
    filename = os.path.basename(header_path)
    name_without_ext = os.path.splitext(filename)[0]
    return "interface_partition_" + name_without_ext

def source_to_partition_name(source_path):
    """Convert source path to implementation partition name."""
    # Get just the filename without extension
    filename = os.path.basename(source_path)
    name_without_ext = os.path.splitext(filename)[0]
    return "implementation_partition_" + name_without_ext

def is_standard_library_header(header):
    """Check if header is a standard library header."""
    std_headers = ['iostream', 'vector', 'string', 'algorithm', 'cassert', 'cstddef', 'memory', 'utility']
    return any(header.startswith(std_header) for std_header in std_headers)

def convert_source_file(input_path):
    """Convert source file to C++ module implementation unit."""
    module_partition = source_to_partition_name(input_path)
    module_name = "Demo"
    comment_header = f"// =============================================\n" \
                     f"// Module implementation unit\n" \
                     f"// Converted from: {input_path}\n" \
                     f"// Script: convert_source_to_module.py\n" \
                     f"// =============================================\n\n"
    
    with open(input_path, 'r') as infile:
        lines = infile.readlines()
    
    # Collect includes
    intra_project_includes = []  # <angle_bracket> includes (non-std)
    intra_project_local_includes = []  # "local.hpp" includes  
    system_includes = []  # "config.hpp" etc.
    std_includes = []  # <iostream>, <vector>, etc.
    
    for line in lines:
        if re.match(r'#pragma once', line):
            continue
            
        # Angle bracket includes
        match = re.match(r'#include\s+<(.*)>', line.strip())
        if match:
            header = match.group(1)
            if is_standard_library_header(header):
                # Standard library headers go to global module fragment
                std_includes.append(line)
            else:
                # Non-standard angle bracket includes are intra-project
                intra_project_includes.append(header)
            continue
            
        # Quote includes
        match = re.match(r'#include\s+"(.*)"', line.strip())
        if match:
            header = match.group(1)
            # Check if intra-project (not system header)
            if not any(header.startswith(sys_header) for sys_header in ['config', 'cassert']):
                intra_project_local_includes.append(header)
            else:
                system_includes.append(line)
            continue
    
    # Build output
    output_lines = [comment_header, "module;\n"]
    
    # Add standard library includes to global module fragment
    for include_line in std_includes:
        output_lines.append(include_line)
    
    # Add system includes to global module fragment
    for include_line in system_includes:
        output_lines.append(include_line)
    
    # Add module declaration (implementation unit with partition name)
    output_lines.append(f"\nmodule {module_name} : {module_partition};\n")
    
    # Add imports for intra-project includes (not re-exported)
    for included in intra_project_includes + intra_project_local_includes:
        partition = header_to_partition_name(included)
        output_lines.append(f"import :{partition};\n")
    
    # Copy all content (no export block)
    for line in lines:
        # Skip already handled content
        if re.match(r'#pragma once', line) or line.strip().startswith('#include'):
            continue
            
        # Copy all other content as-is
        output_lines.append(line)
    
    return output_lines

def main():
    if len(sys.argv) != 3:
        print("Usage: python convert_source_to_module.py <input_source.cpp> <output_module.ixx>")
        sys.exit(1)
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    output_lines = convert_source_file(input_file)
    with open(output_file, 'w') as f:
        f.writelines(output_lines)
    print(f"✅ Generated module implementation unit: {output_file}")

if __name__ == "__main__":
    main() 