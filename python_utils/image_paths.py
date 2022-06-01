import os
import argparse

# Read directory_path and extension from command line arguments
parser = argparse.ArgumentParser()
parser.add_argument('--directory_path', type=str, required=True)
parser.add_argument('--extension', default="jpg", type=str, required=True)
args = parser.parse_args()

output_file = os.path.join(args.directory_path, "image_paths.txt")
# Write the paths to a file
with open(output_file, "w") as f:
    for root, dirs, files in os.walk(args.directory_path):
        for file in files:
            if file.endswith(f".{args.extension}"):
                f.write(os.path.join(root, file) + "\n")        