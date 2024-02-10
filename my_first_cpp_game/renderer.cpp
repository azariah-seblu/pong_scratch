void render_background() {
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			//pixel[y * buffer_width + x] = 0xff5500;
			*pixel++ = (x * y * 499944) % 0xffffff;
		}
	}
}

void clear_screen(unsigned int color) {
	unsigned int* pixel = (unsigned int *)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
}

void draw_rect_in_pixels(unsigned int x0, unsigned int x1, unsigned int y0, unsigned int y1, unsigned int color) {

	x0 = clamp(0, x0, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	x1 = clamp(0, x1, render_state.width);
	y1 = clamp(0, y1, render_state.height);
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = y0; y < y1; y++) {
		pixel = (unsigned int*)render_state.memory + x0 + render_state.width*y;
		for (int x = x0; x < x1; x++) {
			*pixel++= color;
		}
	}
}

void draw_rect(float x, float y, float half_size_x, float half_size_y, unsigned int color) {
	// Change to pixels

	x *= render_state.height;
	y *= render_state.height;

	half_size_x *= render_state.height;
	half_size_y *= render_state.height;

	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;

	draw_rect_in_pixels(x0, x1, y0, y1, color);
}