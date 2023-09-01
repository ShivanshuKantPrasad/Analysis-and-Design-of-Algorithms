OBJ_DIR = build
SRC_DIR =

CFLAGS = `pkg-config --cflags criterion`
LDLIBS = `pkg-config --libs criterion`

$(OBJ_DIR)/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $< -o $@ $(CFLAGS) $(LDLIBS)
	$@ --verbose

clean:
	rm -rf build/*
