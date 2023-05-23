all:
	g++ -o transformation main.cpp sources/Vertex.cpp sources/Matrix.cpp sources/MatrixStack.cpp -I headers/ -lGL -lGLU -lglut
