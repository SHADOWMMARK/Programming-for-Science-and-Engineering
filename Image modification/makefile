proj3.exe: RowColumnClass.o RectangleClass.o project3.o mainMenuOption.o isCinValid.o colorOptions.o ColorImageClass.o ColorClass.o Constant.h PatternClass.o
	g++ RowColumnClass.o RectangleClass.o project3.o mainMenuOption.o isCinValid.o colorOptions.o ColorImageClass.o ColorClass.o PatternClass.o  Constant.h -o proj3.exe

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

mainMenuOption.o: mainMenuOption.cpp mainMenuOption.h
	g++ -c mainMenuOption.cpp -o mainMenuOption.o

isCinValid.o: isCinValid.cpp isCinValid.h
	g++ -c isCinValid.cpp -o isCinValid.o

colorOptions.o: colorOptions.cpp colorOptions.h
	g++ -c colorOptions.cpp -o colorOptions.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

project3.o: project3.cpp
	g++ -c project3.cpp -o project3.o

PatternClass.o: PatternClass.cpp PatternClass.h
	g++ -c PatternClass.cpp -o PatternClass.o

clean:
	rm -rf RowColumnClass.o RectangleClass.o project3.o mainMenuOption.o isCinValid.o colorOptions.o ColorImageClass.o ColorClass.o PatternClass.o  proj3.exe
