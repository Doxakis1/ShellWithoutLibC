make:
	gcc -o exec *.c
clean:
	rm exec
re:
	rm exec && gcc -o exec *.c
run:
	rm exec && gcc -o exec *.c && ./exec	
kill:
	/bin/kill -SIGKILL exec
