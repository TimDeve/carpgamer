.DEFAULT_GOAL := build

build_carp:
	carp --log-memory -b main.carp

build_carp_watch:
	nodemon -w . -x carp --log-memory -b main.carp

clean_carp:
	rm -f src/main.c

build_platform:
	platformio run --target debug

clean_platform:
	platformio run --target clean

upload: build_carp
	platformio run --target upload

build: build_carp build_platform

clean: clean_carp clean_platform

monitor:
	platformio run --target monitor

