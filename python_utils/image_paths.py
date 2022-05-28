import os

directory_path = "/home/menonsandu/Downloads/c1158-nbNrNAmroorTA-output"
output_file = os.path.join(directory_path, "image_paths.txt")
# Write the paths to a file
with open(output_file, "w") as f:
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            if file.endswith(".jpg"):
                f.write(os.path.join(root, file) + "\n")        