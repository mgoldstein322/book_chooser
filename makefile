release: clean
	mkdir build
	cd src && g++ -O3 main.cc book_list.cc -o ../build/book_list

debug: clean
	mkdir build
	cd src && g++ -g main.cc book_list.cc -o ../build/book_list

clean:
	rm -rf build