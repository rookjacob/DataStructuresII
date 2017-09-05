/*
 * @file Struct.h This file contains all of the structures used for a basic
 * directory that processes basic Unix/Linux commands.
 *
 * @author Jacob Rook
 * @date 09/05/2017
 * @info Course COP 4534
 * Project 1
 */
#ifndef STRUCTS_H_
#define STRUCTS_H_


typedef struct Direct{
	char DirName[25];
	struct Directory* Parent;
	struct Directory* HeadDir;
	struct Document* HeadDoc;


}Directory;

typedef struct Doc{
	char DocName[25];
	struct Directory* Parent;
	struct Document* NextDoc;

}Document;

typedef struct input{


}UserInput;


#endif /* STRUCTS_H_ */
