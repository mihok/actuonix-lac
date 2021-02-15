NPM_CMD ?= npm

.PHONY: default clean configure build
default: clean configure build

clean:
	$(NPM_CMD) run clean

configure:
	$(NPM_CMD) run configure

build:
	$(NPM_CMD) run build