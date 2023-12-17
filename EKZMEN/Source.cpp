#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int MAX_NAME_LENGTH = 80;
const int MAX_MANUFACTURER_LENGTH = 80;
const int MAX_GROUP_LENGTH = 80;
const int MAX_DATE_LENGTH = 80;
const int MAX_PRODUCTS = 100;

struct Product
{
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_MANUFACTURER_LENGTH];
    double price;
    char group[MAX_GROUP_LENGTH];
    char date[MAX_DATE_LENGTH];
    char expirationDate[MAX_DATE_LENGTH];
};

struct Warehouse 
{
    Product products[MAX_PRODUCTS];
    int count;

    Warehouse() : count(0) {}
};

//----------------------------------------------------------------------------------------------------------

void displayProduct(const Product& product)
{
    cout << "Название: " << product.name << "\n";
    cout << "Производитель: " << product.manufacturer << "\n";
    cout << "Цена: " << product.price << "\n";
    cout << "Группа товара: " << product.group << "\n";
    cout << "Дата поступления на склад: " << product.date << "\n";
    cout << "Срок годности: " << product.expirationDate << "\n";
    cout << "-----------------------------\n";
}

//----------------------------------------------------------------------------------------------------------

void displayAllProducts(const Warehouse& warehouse)
{
    cout << "\nВсе товары на складе:\n";
    for (int i = 0; i < warehouse.count; i++)
    {
        cout << "Товар #" << i + 1 << ":\n";
        displayProduct(warehouse.products[i]);
    }
}

//----------------------------------------------------------------------------------------------------------

void addProduct(Warehouse& warehouse)
{
    if (warehouse.count < MAX_PRODUCTS) 
    {

        Product& product = warehouse.products[warehouse.count++];

        cout << "Введите название товара: ";
        cin.ignore();
        cin.getline(product.name, MAX_NAME_LENGTH);
        cout << "Введите производителя товара: ";
        cin.getline(product.manufacturer, MAX_MANUFACTURER_LENGTH);

        do 
        {
            cout << "Введите цену товара: ";
            if (cin >> product.price)
            {
                break; 
            }
            else 
            {
                cout << "\nОшибка ввода. Пожалуйста, введите допустимое значение для цены.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (true);

        cout << "Введите группу товара: ";
        cin.ignore();  
        cin.getline(product.group, MAX_GROUP_LENGTH);
        cout << "Введите дату поступления на склад: ";
        cin.getline(product.date, MAX_DATE_LENGTH);
        cout << "Введите срок годности товара: ";
        cin.getline(product.expirationDate, MAX_DATE_LENGTH);

        cout << "\nТовар успешно добавлен на склад.\n";
    }
    else 
    {
        cout << "\nСклад полон, невозможно добавить новый товар.\n";
    }
}

void removeProduct(Warehouse& warehouse) 
{

    cout << "\nТовары до удаления:\n";
    displayAllProducts(warehouse);

    char productName[MAX_NAME_LENGTH];
    cout << "Введите название товара для удаления: ";
    cin.ignore();
    cin.getline(productName, MAX_NAME_LENGTH);

    int foundIndex = -1;
    for (int i = 0; i < warehouse.count; i++) 
    {
        if (strcmp(warehouse.products[i].name, productName) == 0) 
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) 
    {
        warehouse.products[foundIndex] = warehouse.products[--warehouse.count];
        cout << "\nТовар успешно удален со склада.\n";
    }
    else 
    {
        cout << "\nТовар не найден на складе.\n";
    }

    cout << "\nТовары после удаления:\n";
    displayAllProducts(warehouse);
    
}

//----------------------------------------------------------------------------------------------------------

void replaceProduct(Warehouse& warehouse)
{
    cout << "\nТовары до замены:\n";
    displayAllProducts(warehouse);

    char productName[MAX_NAME_LENGTH];
    cout << "Введите название товара для замены: ";
    cin.ignore();
    cin.getline(productName, MAX_NAME_LENGTH);

    int foundIndex = -1;
    for (int i = 0; i < warehouse.count; i++)
    {
        if (strcmp(warehouse.products[i].name, productName) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {

        Product& product = warehouse.products[foundIndex];

        cout << "Введите новое название товара: ";
        cin.getline(product.name, MAX_NAME_LENGTH);

        cout << "Введите нового производителя товара: ";
        cin.getline(product.manufacturer, MAX_MANUFACTURER_LENGTH);

        do
        {
            cout << "Введите новую цену товара: ";
            if (cin >> product.price)
            {
                break;
            }
            else
            {
                cout << "\nОшибка ввода. Пожалуйста, введите допустимое значение для цены.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (true);

        cin.ignore();  
        cout << "Введите новую группу товара: ";
        cin.getline(product.group, MAX_GROUP_LENGTH);

        cout << "Введите новую дату поступления на склад: ";
        cin.getline(product.date, MAX_DATE_LENGTH);

        cout << "Введите новый срок годности товара: ";
        cin.getline(product.expirationDate, MAX_DATE_LENGTH);

        cout << "\nТовар успешно заменен.\n";
    }
    else
    {
        cout << "\nТовар не найден на складе.\n";
    }
    cout << "\nТовары после замены:\n";
    displayAllProducts(warehouse);
}

//----------------------------------------------------------------------------------------------------------

void searchProduct(const Warehouse& warehouse)
{
    int searchChoice;
    cout << "1. Поиск по названию\n";
    cout << "2. Поиск по производителю\n";
    cout << "3. Поиск по цене\n";
    cout << "4. Поиск по группе товара\n";
    cout << "5. Поиск по дате поступления\n";
    cout << "6. Поиск по сроку годности\n";
    cout << "Выберите тип поиска: ";
    cin >> searchChoice;

    switch (searchChoice)
    {
    case 1:
    {
        char searchName[MAX_NAME_LENGTH];
        cout << "Введите название товара для поиска: ";
        cin >> searchName;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].name, searchName) == 0)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "Товар не найден.\n";

        break;
    }
    case 2:
    {
        char searchManufacturer[MAX_MANUFACTURER_LENGTH];
        cout << "Введите производителя для поиска: ";
        cin >> searchManufacturer;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].manufacturer, searchManufacturer) == 0)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\nТовар не найден.\n";

        break;
    }
    case 3:
    {
        double searchPrice;
        cout << "Введите цену для поиска: ";
        cin >> searchPrice;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (warehouse.products[i].price == searchPrice)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\nТовар не найден.\n";

        break;
    }
    case 4:
    {
        char searchGroup[MAX_GROUP_LENGTH];
        cout << "Введите группу товара для поиска: ";
        cin >> searchGroup;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].group, searchGroup) == 0)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\nТовар не найден.\n";

        break;
    }
    case 5:
    {
        char searchDate[MAX_DATE_LENGTH];
        cout << "Введите дату поступления для поиска: ";
        cin >> searchDate;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].date, searchDate) == 0)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\nТовар не найден.\n";

        break;
    }
    case 6:
    {
        char searchExpirationDate[MAX_DATE_LENGTH];
        cout << "Введите срок годности для поиска: ";
        cin >> searchExpirationDate;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].expirationDate, searchExpirationDate) == 0)
            {
                cout << "\nНайден товар:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\nТовар не найден.\n";

        break;
    }
    default:
        cout << "\nНеверный выбор поиска.\n";
    }
}

//----------------------------------------------------------------------------------------------------------

void bubbleSortByPrice(Warehouse& warehouse) 
{
    for (int i = 0; i < warehouse.count - 1; i++) 
    {
        for (int j = 0; j < warehouse.count - i - 1; j++) 
        {
            if (warehouse.products[j].price > warehouse.products[j + 1].price) 
            {
                Product temp = warehouse.products[j];
                warehouse.products[j] = warehouse.products[j + 1];
                warehouse.products[j + 1] = temp;
            }
        }
    }

    cout << "\nТовар успешно отсортирован по цене.\n";

    cout << "\nОтсортированные товары:\n";
    for (int i = 0; i < warehouse.count; i++) 
    {
        cout << "Товар #" << i + 1 << ":\n";
        displayProduct(warehouse.products[i]);
    }
}

void bubbleSortByGroup(Warehouse& warehouse)
{
    for (int i = 0; i < warehouse.count - 1; i++)
    {
        for (int j = 0; j < warehouse.count - i - 1; j++)
        {
            if (strcmp(warehouse.products[j].group, warehouse.products[j + 1].group) > 0)
            {
                Product temp = warehouse.products[j];
                warehouse.products[j] = warehouse.products[j + 1];
                warehouse.products[j + 1] = temp;
            }
        }
    }

    cout << "Товар успешно отсортирован по группе.\n";

    cout << "\nОтсортированные товары:\n";
    for (int i = 0; i < warehouse.count; i++)
    {
        cout << "Товар #" << i + 1 << ":\n";
        displayProduct(warehouse.products[i]);
    }
}

//----------------------------------------------------------------------------------------------------------

void writeProductsToFile(const Warehouse& warehouse, const char* filename)
{
    FILE* file = fopen("products.txt", "w");

    if (!file)
    {
        cout << "Ошибка при открытии файла для записи\n";
        return;
    }

    for (int i = 0; i < warehouse.count; i++)
    {
        const Product& product = warehouse.products[i];
        fprintf(file, "%s,%s,%.2f,%s,%s,%s\n",
            product.name, product.manufacturer, product.price,
            product.group, product.date, product.expirationDate);
    }

    fclose(file);
    cout << "Товары успешно записаны в файл.\n";
}

void loadProductsFromFile(Warehouse& warehouse, const char* filename)
{
    FILE* file = fopen("products.txt", "r");

    if (!file)
    {
        printf("Ошибка при открытии файла для чтения\n");
        return;
    }

    while (!feof(file) && warehouse.count < MAX_PRODUCTS)
    {
        Product& product = warehouse.products[warehouse.count];

        fscanf(file, "%[^,],%[^,],%lf,%[^,],%[^,],%[^\n]\n",
            product.name, product.manufacturer, &product.price,
            product.group, product.date, product.expirationDate);

        warehouse.count++;
    }

    fclose(file);
    printf("Товары успешно загружены из файла.\n");
}

//----------------------------------------------------------------------------------------------------------

int main() 
{

    system("chcp 1251");

    Warehouse warehouse;

    char choice;

    loadProductsFromFile(warehouse, "products.txt");

    do 
    {
        cout << "\nМеню:\n";
        cout << "1. Добавить товар на склад\n";
        cout << "2. Удалить товар со склада\n";
        cout << "3. Заменить товар\n";
        cout << "4. Поиск товара\n";
        cout << "5. Сортировка товара по цене\n";
        cout << "6. Сортировка товара по группе\n";
        cout << "7. Показать все товары на складе\n";
        cout << "0. Выход\n";
        cout << "\nВыберите действие: ";

        cin >> choice;
        cout << endl;

        switch (choice) 
        {
        case '1':
            addProduct(warehouse);
            writeProductsToFile(warehouse, "products.txt");
            break;
        case '2':
            removeProduct(warehouse);
            writeProductsToFile(warehouse, "products.txt");
            break;
        case '3':
            replaceProduct(warehouse);
            writeProductsToFile(warehouse, "products.txt");
            break;
        case '4':
            searchProduct(warehouse);
            break;
        case '5':
            bubbleSortByPrice(warehouse);
            break;
        case '6':
            bubbleSortByGroup(warehouse);
            break;
        case '7':
            displayAllProducts(warehouse);
            break;
        case '0':
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор. Повторите попытку.\n";
        }
    } while (choice != '0');

    return 0;
}