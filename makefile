book.exe: bookimp.o bookapp.o
	g++ bookimp.o bookapp.o -o book.exe
bookimp.o: bookimp.cpp
	g++ -c bookimp.cpp
bookapp.o: bookapp.cpp
	g++ -c bookapp.cpp