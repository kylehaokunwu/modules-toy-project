import os
import re
import sys

def extract_partition_from_file(filepath):
    with open(filepath, 'r') as f:
        for line in f:
            match = re.match(r'\s*export\s+module\s+Demo\s*:\s*(\S+);', line)
            if match:
                return match.group(1)
    return None

def generate_primary_module(output_path, module_files):
    partition_names = []

    for file in module_files:
        partition = extract_partition_from_file(file)
        if partition:
            partition_names.append(partition)

    with open(output_path, 'w') as out:
        out.write("module;\n")
        out.write("export module Demo;\n\n")
        for partition in sorted(partition_names):
            out.write(f"export import :{partition};\n")

    print(f"✅ Generated primary module interface unit: {output_path}")

def main():
    if len(sys.argv) < 3:
        print("Usage: python generate_primary_module.py <output_file.ixx> <module1.ixx> [<module2.ixx> ...]")
        sys.exit(1)

    output_file = sys.argv[1]
    module_files = sys.argv[2:]

    generate_primary_module(output_file, module_files)

if __name__ == "__main__":
    main()
