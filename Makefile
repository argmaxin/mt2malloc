.PHONY: fmt gfmt gvenv ctags gdocwx docwx clean fmt-check

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MKFILE_DIR := $(dir $(MKFILE_PATH))

fmt:
	git ls-files '*.c' | xargs clang-format -i 
	git ls-files '*.h' | xargs clang-format -i
	cargo fmt

gfmt:
	git ls-files \
	| $(MKFILE_DIR)venv/bin/python tools/genmacro.py -L - \
	| $(MKFILE_DIR)venv/bin/python tools/genfmt.py .clang-format-base.yml \
	> .clang-format

fmt-check:
	git ls-files | xargs clang-format --dry-run --Werror

gvenv:
	python -m venv $(MKFILE_DIR)venv
	$(MKFILE_DIR)venv/bin/pip install clang

ctags:
	git ls-files | ctags -L - 

gdocwx:
	cargo install docwx

docwx:
	git ls-files | docwx -L -o $(MKFILE_DIR)spec

clean:
	rm tags
	rm .clang-format
