import os
import sys
import re

def header_to_partition_name(header_path):
    """Convert header path to module partition name."""
    # Get just the filename without extension
    filename = os.path.basename(header_path)
    name_without_ext = os.path.splitext(filename)[0]
    return "interface_partition_" + name_without_ext

def is_standard_library_header(header):
    """Check if header is a standard library header."""
    std_headers = ['iostream', 'vector', 'string', 'algorithm', 'cassert', 'cstddef', 'memory', 'utility']
    return any(header.startswith(std_header) for std_header in std_headers)

def convert_header_file(input_path):
    """Convert header file to C++ module partition."""
    module_partition = header_to_partition_name(input_path)
    module_name = "Demo"

    # Determine comment header type
    if os.path.basename(input_path) == "demo.hpp":
        unit_type = "Primary module interface unit"
    else:
        unit_type = "Module interface unit"

    comment_header = f"// =============================================\n" \
                     f"// {unit_type}\n" \
                     f"// Converted from: {input_path}\n" \
                     f"// Script: convert_header_to_module.py\n" \
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

    # Add export module declaration
    output_lines.append(f"\nexport module {module_name} : {module_partition};\n")

    # Add export imports for intra-project includes
    for included in intra_project_includes + intra_project_local_includes:
        partition = header_to_partition_name(included)
        output_lines.append(f"export import :{partition};\n")

    # Add export block
    output_lines.append("\nexport {\n")

    # Copy namespace content
    namespace_declared = False
    namespace_depth = 0
    
    for line in lines:
        # Skip already handled content
        if re.match(r'#pragma once', line) or line.strip().startswith('#include'):
            continue
            
        # Handle namespace declaration
        if 'namespace' in line and '{' in line:
            if not namespace_declared:
                output_lines.append(line)
                namespace_declared = True
            namespace_depth += 1
            continue
            
        # Handle namespace closing
        if '}' in line:
            output_lines.append(line)
            namespace_depth -= 1
            if namespace_depth == 0:  # End of main namespace
                continue
        
        # Handle namespace comment
        elif '// namespace' in line and namespace_depth == 0:
            output_lines.append(line)
            output_lines.append("} // end export\n")
            return output_lines
        
        # Copy namespace content
        elif namespace_declared:
            output_lines.append(line)

    # Fallback: close export block
    output_lines.append("} // end export\n")
    return output_lines

def main():
    if len(sys.argv) != 3:
        print("Usage: python convert_header_to_module.py <input_header.h> <output_module.ccm>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    output_lines = convert_header_file(input_file)

    with open(output_file, 'w') as f:
        f.writelines(output_lines)

    # Consistent confirmation message
    if os.path.basename(input_file) == "demo.hpp":
        print(f"✅ Generated primary module interface unit: {output_file}")
    else:
        print(f"✅ Generated module interface unit: {output_file}")

if __name__ == "__main__":
    main()
