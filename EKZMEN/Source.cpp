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
    cout << "��������: " << product.name << "\n";
    cout << "�������������: " << product.manufacturer << "\n";
    cout << "����: " << product.price << "\n";
    cout << "������ ������: " << product.group << "\n";
    cout << "���� ����������� �� �����: " << product.date << "\n";
    cout << "���� ��������: " << product.expirationDate << "\n";
    cout << "-----------------------------\n";
}

//----------------------------------------------------------------------------------------------------------

void displayAllProducts(const Warehouse& warehouse)
{
    cout << "\n��� ������ �� ������:\n";
    for (int i = 0; i < warehouse.count; i++)
    {
        cout << "����� #" << i + 1 << ":\n";
        displayProduct(warehouse.products[i]);
    }
}

//----------------------------------------------------------------------------------------------------------

void addProduct(Warehouse& warehouse)
{
    if (warehouse.count < MAX_PRODUCTS) 
    {

        Product& product = warehouse.products[warehouse.count++];

        cout << "������� �������� ������: ";
        cin.ignore();
        cin.getline(product.name, MAX_NAME_LENGTH);
        cout << "������� ������������� ������: ";
        cin.getline(product.manufacturer, MAX_MANUFACTURER_LENGTH);

        do 
        {
            cout << "������� ���� ������: ";
            if (cin >> product.price)
            {
                break; 
            }
            else 
            {
                cout << "\n������ �����. ����������, ������� ���������� �������� ��� ����.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (true);

        cout << "������� ������ ������: ";
        cin.ignore();  
        cin.getline(product.group, MAX_GROUP_LENGTH);
        cout << "������� ���� ����������� �� �����: ";
        cin.getline(product.date, MAX_DATE_LENGTH);
        cout << "������� ���� �������� ������: ";
        cin.getline(product.expirationDate, MAX_DATE_LENGTH);

        cout << "\n����� ������� �������� �� �����.\n";
    }
    else 
    {
        cout << "\n����� �����, ���������� �������� ����� �����.\n";
    }
}

void removeProduct(Warehouse& warehouse) 
{

    cout << "\n������ �� ��������:\n";
    displayAllProducts(warehouse);

    char productName[MAX_NAME_LENGTH];
    cout << "������� �������� ������ ��� ��������: ";
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
        cout << "\n����� ������� ������ �� ������.\n";
    }
    else 
    {
        cout << "\n����� �� ������ �� ������.\n";
    }

    cout << "\n������ ����� ��������:\n";
    displayAllProducts(warehouse);
    
}

//----------------------------------------------------------------------------------------------------------

void replaceProduct(Warehouse& warehouse)
{
    cout << "\n������ �� ������:\n";
    displayAllProducts(warehouse);

    char productName[MAX_NAME_LENGTH];
    cout << "������� �������� ������ ��� ������: ";
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

        cout << "������� ����� �������� ������: ";
        cin.getline(product.name, MAX_NAME_LENGTH);

        cout << "������� ������ ������������� ������: ";
        cin.getline(product.manufacturer, MAX_MANUFACTURER_LENGTH);

        do
        {
            cout << "������� ����� ���� ������: ";
            if (cin >> product.price)
            {
                break;
            }
            else
            {
                cout << "\n������ �����. ����������, ������� ���������� �������� ��� ����.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        } while (true);

        cin.ignore();  
        cout << "������� ����� ������ ������: ";
        cin.getline(product.group, MAX_GROUP_LENGTH);

        cout << "������� ����� ���� ����������� �� �����: ";
        cin.getline(product.date, MAX_DATE_LENGTH);

        cout << "������� ����� ���� �������� ������: ";
        cin.getline(product.expirationDate, MAX_DATE_LENGTH);

        cout << "\n����� ������� �������.\n";
    }
    else
    {
        cout << "\n����� �� ������ �� ������.\n";
    }
    cout << "\n������ ����� ������:\n";
    displayAllProducts(warehouse);
}

//----------------------------------------------------------------------------------------------------------

void searchProduct(const Warehouse& warehouse)
{
    int searchChoice;
    cout << "1. ����� �� ��������\n";
    cout << "2. ����� �� �������������\n";
    cout << "3. ����� �� ����\n";
    cout << "4. ����� �� ������ ������\n";
    cout << "5. ����� �� ���� �����������\n";
    cout << "6. ����� �� ����� ��������\n";
    cout << "�������� ��� ������: ";
    cin >> searchChoice;

    switch (searchChoice)
    {
    case 1:
    {
        char searchName[MAX_NAME_LENGTH];
        cout << "������� �������� ������ ��� ������: ";
        cin >> searchName;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].name, searchName) == 0)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "����� �� ������.\n";

        break;
    }
    case 2:
    {
        char searchManufacturer[MAX_MANUFACTURER_LENGTH];
        cout << "������� ������������� ��� ������: ";
        cin >> searchManufacturer;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].manufacturer, searchManufacturer) == 0)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\n����� �� ������.\n";

        break;
    }
    case 3:
    {
        double searchPrice;
        cout << "������� ���� ��� ������: ";
        cin >> searchPrice;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (warehouse.products[i].price == searchPrice)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\n����� �� ������.\n";

        break;
    }
    case 4:
    {
        char searchGroup[MAX_GROUP_LENGTH];
        cout << "������� ������ ������ ��� ������: ";
        cin >> searchGroup;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].group, searchGroup) == 0)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\n����� �� ������.\n";

        break;
    }
    case 5:
    {
        char searchDate[MAX_DATE_LENGTH];
        cout << "������� ���� ����������� ��� ������: ";
        cin >> searchDate;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].date, searchDate) == 0)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\n����� �� ������.\n";

        break;
    }
    case 6:
    {
        char searchExpirationDate[MAX_DATE_LENGTH];
        cout << "������� ���� �������� ��� ������: ";
        cin >> searchExpirationDate;

        bool found = false;
        for (int i = 0; i < warehouse.count; i++)
        {
            if (strcmp(warehouse.products[i].expirationDate, searchExpirationDate) == 0)
            {
                cout << "\n������ �����:\n";
                displayProduct(warehouse.products[i]);
                found = true;
            }
        }

        if (!found)
            cout << "\n����� �� ������.\n";

        break;
    }
    default:
        cout << "\n�������� ����� ������.\n";
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

    cout << "\n����� ������� ������������ �� ����.\n";

    cout << "\n��������������� ������:\n";
    for (int i = 0; i < warehouse.count; i++) 
    {
        cout << "����� #" << i + 1 << ":\n";
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

    cout << "����� ������� ������������ �� ������.\n";

    cout << "\n��������������� ������:\n";
    for (int i = 0; i < warehouse.count; i++)
    {
        cout << "����� #" << i + 1 << ":\n";
        displayProduct(warehouse.products[i]);
    }
}

//----------------------------------------------------------------------------------------------------------

void writeProductsToFile(const Warehouse& warehouse, const char* filename)
{
    FILE* file = fopen("products.txt", "w");

    if (!file)
    {
        cout << "������ ��� �������� ����� ��� ������\n";
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
    cout << "������ ������� �������� � ����.\n";
}

void loadProductsFromFile(Warehouse& warehouse, const char* filename)
{
    FILE* file = fopen("products.txt", "r");

    if (!file)
    {
        printf("������ ��� �������� ����� ��� ������\n");
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
    printf("������ ������� ��������� �� �����.\n");
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
        cout << "\n����:\n";
        cout << "1. �������� ����� �� �����\n";
        cout << "2. ������� ����� �� ������\n";
        cout << "3. �������� �����\n";
        cout << "4. ����� ������\n";
        cout << "5. ���������� ������ �� ����\n";
        cout << "6. ���������� ������ �� ������\n";
        cout << "7. �������� ��� ������ �� ������\n";
        cout << "0. �����\n";
        cout << "\n�������� ��������: ";

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
            cout << "����� �� ���������.\n";
            break;

        default:
            cout << "�������� �����. ��������� �������.\n";
        }
    } while (choice != '0');

    return 0;
}