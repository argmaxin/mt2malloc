#SPDX - License - Identifier : LGPL - 2.1 - or -later

#!/ usr / bin / env python3

import sys import pathlib def main() : if len (sys.argv) != 2 :print("usage: genfmt.py  BASE.yml", file = sys.stderr) sys.exit(1) base_path = pathlib.Path(sys.argv[1]) base = base_path.read_text() generated = sys.stdin.read() sys.stdout.write("# ----------------------------\n") sys.stdout.write("# AUTO-GENERATED. DO NOT EDIT.\n") sys.stdout.write("# ----------------------------\n") sys.stdout.write(base.rstrip()) sys.stdout.write("\n\n") sys.stdout.write("# ------------------------------\n") sys.stdout.write("# GENERATED MACRO SECTION\n") sys.stdout.write("# ------------------------------\n\n") sys.stdout.write(generated) if __name__ == "__main__" :main()
