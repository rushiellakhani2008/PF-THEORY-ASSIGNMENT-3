#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **lines = NULL;
int size = 0;
int capacity = 0;

void checkAlloc(void *ptr) {
    if (!ptr) {
        perror("Memory allocation failed");
        exit(1);
    }
}

void ensureCapacity() {
    if (size < capacity) return;
    capacity = (capacity == 0) ? 4 : capacity * 2;
    char **tmp = (char **)realloc(lines, capacity * sizeof(char *));
    checkAlloc(tmp);
    lines = tmp;
}

/* Replacement for getline() - works everywhere */
char* mygetline() {
    char buffer[1024];

    if (!fgets(buffer, sizeof(buffer), stdin))
        return NULL;

    buffer[strcspn(buffer, "\n")] = '\0';

    char *line = (char*)malloc((strlen(buffer)+1) * sizeof(char*));
    checkAlloc(line);
    strcpy(line, buffer);

    return line;
}

void insertLine(int index, const char *text) {
    if (index < 0 || index > size) {
        printf("Invalid index\n");
        return;
    }

    ensureCapacity();

    for (int i = size; i > index; i--)
        lines[i] = lines[i - 1];

    lines[index] =(char*) malloc((strlen(text)+1) * sizeof(char*));
    checkAlloc(lines[index]);
    strcpy(lines[index], text);

    size++;
}

void deleteLine(int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return;
    }

    free(lines[index]);
    for (int i = index; i < size - 1; i++)
        lines[i] = lines[i + 1];

    size--;
}

void printAllLines() {
    if (size == 0) {
        printf("(empty)\n");
        return;
    }

    for (int i = 0; i < size; i++)
        printf("%d: %s\n", i + 1, lines[i]);
}

void shrinkToFit() {
    if (size == 0) {
        free(lines);
        lines = NULL;
        capacity = 0;
        return;
    }

    char **tmp = (char**)realloc(lines, size * sizeof(char *));
    checkAlloc(tmp);
    lines = tmp;
    capacity = size;
}

void freeAll() {
    for (int i = 0; i < size; i++)
        free(lines[i]);
    free(lines);

    lines = NULL;
    size = 0;
    capacity = 0;
}

void saveToFile(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Cannot open file\n");
        return;
    }

    for (int i = 0; i < size; i++)
        fprintf(f, "%s\n", lines[i]);

    fclose(f);
    printf("Saved.\n");
}

void loadFromFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file\n");
        return;
    }

    freeAll();

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), f)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        insertLine(size, buffer);
    }

    fclose(f);
    printf("Loaded.\n");
}


int main() {
    int choice;

    while (1) {
        printf("1.Insert\n2.Delete\n3.Print\n4.Save\n5.Load\n6.Shrink\n7.Clear\n8.Exit\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        int index;
        char filename[256];
        getchar();

        if (choice == 1) {
            printf("Enter insert index (1..%d): ", size + 1);
            scanf("%d", &index);
            getchar();

            printf("Enter text: ");
            char *txt = mygetline();
            insertLine(index - 1, txt);
            free(txt);
        }

        else if (choice == 2) {
            printf("Enter delete index (1..%d): ", size);
            scanf("%d", &index);
            getchar();
            deleteLine(index - 1);
        }

        else if (choice == 3)
            printAllLines();

        else if (choice == 4) {
            printf("Enter filename: ");
            scanf("%s", filename);
            saveToFile(filename);
        }

        else if (choice == 5) {
            printf("Enter filename: ");
            scanf("%s", filename);
            loadFromFile(filename);
        }

        else if (choice == 6)
            shrinkToFit();

        else if (choice == 7)
            freeAll();

        else if (choice == 8)
            break;
    }

    freeAll();
    return 0;
}

