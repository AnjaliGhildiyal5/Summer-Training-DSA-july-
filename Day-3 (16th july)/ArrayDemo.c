
#include <stdio.h>

#define MAX_SIZE 100 // Maximum capacity of the array

// Function Prototypes
void display(int arr[], int size);
void insert(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);
int search(int arr[], int size, int target);
void update(int arr[], int size, int element, int position);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, index;

    // 1. Initialize Array with User Input
    printf("Enter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 0) {
        printf("Invalid size selection.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // 2. Menu-driven operations loop
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Traverse (Display)\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Update Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);

        switch (choice) {
            case 1:
                display(arr, size);
                break;

            case 2:
                if (size >= MAX_SIZE) {
                    printf("Array is full! Cannot insert.\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter 0-indexed position (0 to %d): ", size);
                scanf("%d", &position);
                
                if (position < 0 || position > size) {
                    printf("Invalid position!\n");
                } else {
                    insert(arr, &size, element, position);
                    printf("Element inserted successfully.\n");
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Array is empty! Cannot delete.\n");
                    break;
                }
                printf("Enter 0-indexed position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                
                if (position < 0 || position >= size) {
                    printf("Invalid position!\n");
                } else {
                    deleteElement(arr, &size, position);
                    printf("Element deleted successfully.\n");
                }
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                index = search(arr, size, element);
                if (index != -1) {
                    printf("Element found at index: %d\n", index);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;

            case 5:
                printf("Enter 0-indexed position to update (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter new value: ");
                    scanf("%d", &element);
                    update(arr, size, element, position);
                    printf("Element updated successfully.\n");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Operation 1: Traverse and Display
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Operation 2: Insertion
void insert(int arr[], int *size, int element, int position) {
    // Shift elements to the right to make room
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element; // Insert the element
    (*size)++; // Increase size tracking
}

// Operation 3: Deletion
void deleteElement(int arr[], int *size, int position) {
    // Shift elements to the left to overwrite the target index
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrease size tracking
}

// Operation 4: Linear Search
int search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return matching index
        }
    }
    return -1; // Target not found
}

// Operation 5: Update
void update(int arr[], int size, int element, int position) {
    arr[position] = element; // Explicit index reassignment
}
