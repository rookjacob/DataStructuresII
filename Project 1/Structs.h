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

/*
 * @brief DirectoryFile Structure used for the Directories and files.
 *
 * @var Type The distinction between a directory and a file will be made by
 * the Type variable. A directory will have a "D" assigned to Type and a file
 * will have an "F" assigned to Type.
 *
 * @var DirName This variable will store the name of the directory or file.
 *
 * @var Parent This variable is a pointer to the directory that the current
 * file is in.
 *
 * @var HeadDirList This variable is the head of the directory/file list that
 * are in the Directory.
 */
typedef struct DirFile{
	char Type;
	char DirName[25];
	struct DirectoryFile* Parent;
	struct DirectoryFile* HeadDirList;

}DirectoryFile;

DirectoryFile ROOT;			//This is the root for all the files.
DirectoryFile *CURR;		//Pointer to the current location in the tree



typedef struct input{
	char Command[8];
	char SecondWord[25];
	char ThirdWord[25];

}UserInput;


#endif /* STRUCTS_H_ */
