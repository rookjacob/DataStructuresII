/*
 * Structs.h
 * Jacob Rook
 * Data Structures and Algorithms II
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


#endif /* STRUCTS_H_ */
