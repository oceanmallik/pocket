import os
import json

# Ignore folders and files that aren't part of your code collection
IGNORED_DIRS = {'.git', '.github', 'css', 'js', 'assets'}
IGNORED_FILES = {'index.html', 'generate_tree.py', 'tree.json', 'README.md'}
# Define which file types to look for
ALLOWED_EXTENSIONS = {'.c', '.cpp', '.cs', '.rs', '.py', '.h', '.hpp'}

def build_tree(dir_path):
    tree = []
    # Sort alphabetically to keep the UI organized
    for entry in sorted(os.listdir(dir_path)):
        full_path = os.path.join(dir_path, entry)
        # Get the path relative to the root so the web frontend can fetch it easily
        rel_path = os.path.relpath(full_path, '.').replace('\\', '/')

        if os.path.isdir(full_path):
            if entry in IGNORED_DIRS:
                continue
            children = build_tree(full_path)
            # Only add folders if they actually contain valid code files
            if children: 
                tree.append({"type": "folder", "name": entry, "children": children})
        else:
            if entry in IGNORED_FILES:
                continue
            _, ext = os.path.splitext(entry)
            if ext in ALLOWED_EXTENSIONS:
                tree.append({"type": "file", "name": entry, "path": rel_path})
    return tree

if __name__ == '__main__':
    directory_tree = build_tree('.')
    with open('tree.json', 'w') as f:
        json.dump(directory_tree, f, indent=2)