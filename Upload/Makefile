#object Upload
#create by wn

CXX = g++

BIN = upload.cgi

MYFLAGS = -I"D:/WN/apache_htdocs/cgi/includes"

MYLIBS = -L"D:/WN/apache_htdocs/cgi/src"

CGICCFLAGS = -I"D:/WN/cgicc_3_2_10"

SOURCE = upload.cpp ../src/HttpHandle.cpp

LINKOBJ = $(SOURCE:%.cpp=%.o)

all:$(BIN)

test:
	echo $(LINKOBJ)

$(BIN):$(LINKOBJ)
	$(CXX) $(LINKOBJ) -o $(BIN)

%.o:%.cpp
	$(CXX) $< -c -o $@

../src/%.o:../src/%.cpp
	$(CXX) $< -c -o $@ $(MYFLAGS)

.PHONY:clean all

clean:
	-rm $(LINKOBJ)


