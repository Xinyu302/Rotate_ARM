# make mat_fp16

mat_fp16: armcommon_tinycv_rotate_fp16.c armcommon_tinycv_rotate_ui8.c main_fp16.c
	clang $^ -O3  -o $@

run: mat_fp16
	./mat_fp16

clean:
	rm -rf mat_fp16

# clang armcommon_tinycv_rotate_fp16.c armcommon_tinycv_rotate_ui8.c main_fp16.c -O3  -o mat_fp16