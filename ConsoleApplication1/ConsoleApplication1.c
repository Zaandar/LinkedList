#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define SIZE 500


typedef struct produceItem
{
	char produce[20];
	char type[20];
	char soldBy[20];
	float price;
	int quantityInStock;
	struct produceItem* next;
} *head;



void add(char buff[255], int count) {

	printf("%d\t", count);

	// allocate memory for a produceItem struct
	struct produceItem* tempProduceItem = (struct produceItem*)malloc(sizeof(struct produceItem));

	char* nextTok = NULL;

	// read the first item (comma-separated)
	char* token = strtok_s(buff, ",", &nextTok);

	// make sure we have a pointer to the memory we allocated
	if (tempProduceItem != NULL) {
		int numItems = sscanf_s(token, "%[^,\n] %[^,\n]", 
			tempProduceItem->produce, 20,
			tempProduceItem->type, 20
		);

		printf("read %d items", numItems);
	}

	while (token != NULL) {

		printf("%s\t\t", token);

		// get the next token from the original string
		token = (strtok_s(NULL, ",", &nextTok));

		

		// make sure we have a pointer to the memory we allocated
		if (tempProduceItem != NULL) {
			

			//if (tempProduceItem != NULL) {
				//fscanf(fp, "%[^,],%[^,],%d\n", first_name, last_name, &grade);
				//int numItems = sscanf_s(buff, "%20s[^,] %20s[^,] %20s[^,] %f[^,] %d", tempProduceItem->produce, tempProduceItem->type, tempProduceItem->soldBy, &tempProduceItem->price, &tempProduceItem->quantityInStock);
				// %4[^,] means read at most four characters or until a comma is encountered.
				//int numItems = sscanf_s(tempProduceItem, "%20s, %20s, %20s, %f, %d", buff);
				//printf("read %d items", numItems);
			//}


			// produce
			//memcpy(tempProduceItem->produce, token, strlen(token) + 1);

			// type
			//memcpy(tempProduceItem->type, token, strlen(token) + 1);
			// soldBy
			// price
			// quantityInStock


			// get the next token
			//token = (strtok_s(NULL, ",", &nextTok));

		}
	}
}







void read() {

	printf("reading...\n");
	char buff[255];
	FILE* pF;
	errno_t err;
	int count = 0;

	//printf("%d\t", count);

	// allocate memory for a produceItem struct
	struct produceItem* tempProduceItem = (struct produceItem*)malloc(sizeof(struct produceItem));

	err = fopen_s(&pF, "C:\\tmp\\Assignment7Input.txt", "r");


	if (pF != NULL) {
		printf("File Opened. \n");

		while (!feof(pF)) { // while we dont reach the end of the file
			fgets(buff, 255, (FILE*)pF); // read until a newline is found
			add(buff, ++count); // add item
		}
	}
	else {
		printf("Error Opening File: %d\n", err);
	}
}








//main function
int main() {

	int selection;
	int menu;

	printf("Make a selection.\n\n");
	printf("1. Stock Produce Department\n");
	printf("2. Display Produce Inventory\n");
	printf("3. Output\n");
	printf("4. Exit\n");

	scanf_s("%d", &selection);

	switch (selection) {
	case 1: {
		read();
		break;
	}
	case 2: {
		printf("2");
		menu = 2;
		break;
	}
	case 3: {
		printf("3");
		menu = 3;
		break;
	}
	case 4: {
		printf("4");
		menu = 4;
		break;
	}
	}

}