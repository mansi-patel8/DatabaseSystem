/*
* Name: Mansi Patel
* Purpose: This program will create/manipulate a generic database for multiple possible purposes.
		 - In this particular program it will Add entity, Edit entity (Add/Edit/Delete field and it's label) and remove it from the database.
* Pseducode/ Program outline logic:
		- create union for fields with diffrent types.
		- create a structure that takes fields from union and has labels for those fields. It also stores data for 'last used datatype' - to perform the edit opeation
		- take user input for main menu and depending upon the the input go to associated menu option
			- take user input for Edit menu option for adding, editing and removing fields
		- always ask for which entity to update - KEY
		- only for editing field option - this program will ask for the field to check if it exists, howvere since this code uses the concept of unions, it will prompt you to update the field whose datatype was lastly accessed by the user. Meaning, you would like to update the char field option that you've added, howvere after that if you have accessed the boolean field you will be able to update the bool field instead of char.
		- perform delete option for field only and entity.
		- print the entity.
*/

#include <iostream> 
#include <string>
#include <iomanip> 

using namespace std; 

const int DATABASE_SIZE = 2;
const int ARRAY_SIZE = 128;

struct entity
{
	unsigned int id = 0;

	int numberOfFields = 0;
	char fieldNameForChar[ARRAY_SIZE] = {};
	char charField[ARRAY_SIZE] = {};
	char fieldNameForInt[ARRAY_SIZE] = {};
	int intField = 0;
	char fieldNameForFloatOne[ARRAY_SIZE] = {};
	double floatFieldOne = 0.0f;
	char fieldNameForFloatTwo[ARRAY_SIZE] = {};
	double floatFieldTwo = 0.0f;
	char fieldNameForBool[ARRAY_SIZE] = {};
	bool boolField = false;

	char editField[ARRAY_SIZE] = {};
	char deleteField[ARRAY_SIZE] = {};
};

int main()
{
	int mainMenuUserInput;
	int searchUserInput;
	int editMenuUserInput;
	int removeUserInput;
	int printUserInput;
	int fieldType;
	char editFieldUserInput[ARRAY_SIZE];	//userinput as text to find which field to edit - if the field even exists in the system

	bool flag = true;

	cout << "Generic database creation program." << endl;
	cout << "What would you like to do next?" << endl;
	cout << "1. Add entity" << endl;
	cout << "2. Edit entity" << endl;
	cout << "3. Remove entity" << endl;
	cout << "4. Print entity info" << endl;
	cout << "5. Stop the program" << endl;

	cin >> mainMenuUserInput;

	int i = 0;
	struct entity databaseEntity[DATABASE_SIZE];

	while (flag)
	{
		if (mainMenuUserInput == 1) 																			//1. Add entity
		{
			if (i < 2) {
				cout << "---------------------Option 1------------------------" << endl;
				databaseEntity[i].id = i;
				cout << "The new entity with " << databaseEntity[i].id << " has been added to the database." << endl;
				i++;
			}
		}
		else if (mainMenuUserInput == 2) 																	//2. Edit entity
		{
			cout << "---------------------Option 2------------------------" << endl;
			cout << "Please enter ID of the entity to edit: " << endl;

			cin.ignore(INT_MAX, '\n');
			cin >> searchUserInput;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter correct input value here! Now Try again: ";
				cin >> searchUserInput;
			}

			bool foundSerch = false;

			for (int x = 0; x < DATABASE_SIZE; x++)
			{
				if (searchUserInput == databaseEntity[x].id)
				{
					foundSerch = true;
				}
			}
			cout << "Editing entity ID ( " << searchUserInput << " )" << endl;
			if (foundSerch == false)
			{
				cout << "ID " << searchUserInput << " does not exists in Database" << endl << endl;
			}

			while (foundSerch == true)
			{
				cout << "What would you like to do next ?" << endl;
				cout << "1. Add field" << endl;
				cout << "2. Edit field" << endl;
				cout << "3. Remove field" << endl;
				cout << "4. Go back to main menu" << endl;
				cin >> editMenuUserInput;

				if (editMenuUserInput == 1) 					//1. Add field in the entity
				{
					int countForChar = 0;
					cin.ignore(INT_MAX, '\n');

					cout << "1. Add field" << endl;
					cout << "How many fields you would like to add? ";
					cin >> databaseEntity[searchUserInput].numberOfFields;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Please enter correct input value here! Now Try again: ";
						cin >> databaseEntity[searchUserInput].numberOfFields;
					}

					for (int y = 0; y < databaseEntity[searchUserInput].numberOfFields; y++)
					{
						cout << "Select type: 0 for characters, 1 for integer, 2 for float, 3 for boolean: ";
						cin >> fieldType;
						while (cin.fail() || (fieldType < 0 || fieldType >= 4))
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cout << "Please enter correct input value here! Now Try again: ";
							cin >> fieldType;
						}

						if (fieldType == 0)
						{
							cin.ignore(INT_MAX, '\n');
							cout << "Enter char field name: ";
							cin.getline(databaseEntity[searchUserInput].fieldNameForChar, ARRAY_SIZE);
							while (cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "Please enter correct input value here! Now Try again: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForChar, ARRAY_SIZE);
							}

							cout << "Enter char field value: ";
							cin.getline(databaseEntity[searchUserInput].charField, ARRAY_SIZE);
							while (cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "Please enter correct input value here! Now Try again: ";
								cin.getline(databaseEntity[searchUserInput].charField, ARRAY_SIZE);
							}
						}
						else if (fieldType == 1)
						{
							cin.ignore(INT_MAX, '\n');
							cout << "Enter int field name: ";
							cin.getline(databaseEntity[searchUserInput].fieldNameForInt, ARRAY_SIZE);
							while (cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "Please enter correct input value here! Now Try again: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForInt, ARRAY_SIZE);
							}

							cout << "Enter int field value: ";
							while (!(cin >> databaseEntity[searchUserInput].intField) || cin.get() != '\n') {
								cout << "ERROR: Please enter integers only! Now Try Again: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
						}
						else if (fieldType == 2)
						{
							if (countForChar == 0)
							{
								cin.ignore(INT_MAX, '\n');
								cout << "Enter float field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForFloatOne, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForFloatOne, ARRAY_SIZE);
								}

								cout << "Enter float field value: ";
								while (!(cin >> databaseEntity[searchUserInput].floatFieldOne))
								{
									cout << "ERROR: Please enter floats only! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								};
							}
							if (countForChar == 1) {
								cin.ignore(INT_MAX, '\n');
								cout << "Enter float field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForFloatTwo, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForFloatTwo, ARRAY_SIZE);
								}

								cout << "Enter float field value: ";
								while (!(cin >> databaseEntity[searchUserInput].floatFieldTwo))
								{
									cout << "ERROR: Please enter floats only! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								};
							}
							countForChar++;
						}
						else if (fieldType == 3)
						{
							cin.ignore(INT_MAX, '\n');
							cout << "Enter bool field name: ";
							cin.getline(databaseEntity[searchUserInput].fieldNameForBool, ARRAY_SIZE);
							while (cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cout << "Please enter correct input value here! Now Try again: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForBool, ARRAY_SIZE);
							}

							cout << "Enter bool field value (Enter 0 for False and 1 for True): ";
							while (!(cin >> databaseEntity[searchUserInput].boolField) || cin.get() != '\n') {
								cout << "ERROR: Please enter 0 or 1 only for Boolean ! Now Try Again: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
						}
						else
						{
							cout << "Invalid input. Please enter the field type option between 0 to 3." << endl;
						}
					}
				}
				else if (editMenuUserInput == 2)  			//2. Edit field in the entity
				{
					cin.ignore(INT_MAX, '\n');
					cout << "----------Edit Menu----------" << endl;
					cout << "2. Edit field" << endl;
					cout << "Which field type you would like edit?" << endl;
					cout << "Select type: 0 for characters, 1 for integer, 2 for float, 3 for boolean: ";
					cin >> fieldType;
					while (cin.fail() || (fieldType < 0 || fieldType >= 4))
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Please enter correct input value here! Now Try again: ";
						cin >> fieldType;
					}

					cin.ignore(INT_MAX, '\n');
					//check if the field even exists in the system
					cout << "Which field you would like edit? ";
					cin.getline(editFieldUserInput, ARRAY_SIZE);
					//error check for correct userinput
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Please enter correct input value here! Now Try again: ";
						cin.getline(editFieldUserInput, ARRAY_SIZE);
					}
					bool findField = false;

					for (int x = searchUserInput; x < DATABASE_SIZE; x++)
					{
						//check the edit user input with label
						if ((string(editFieldUserInput) == string(databaseEntity[x].fieldNameForChar)) ||
							(string(editFieldUserInput) == string(databaseEntity[x].fieldNameForInt)) ||
							(string(editFieldUserInput) == string(databaseEntity[x].fieldNameForFloatOne)) ||
							(string(editFieldUserInput) == string(databaseEntity[x].fieldNameForFloatTwo)) ||
							(string(editFieldUserInput) == string(databaseEntity[x].fieldNameForBool)) )
						{
							findField = true;
						}

						//if not found the field
						if (findField == false)
						{
							cout << "Field does not exists in Database" << endl;
							cout << "This is case senstive so please enter the exact field label you added for the field. Also, if you have any spaces make sure to add those too!" << endl;
							cout << "Try again!" << endl << endl;
						}

						else
						{
							if (fieldType == 0 && string(editFieldUserInput) == string(databaseEntity[x].fieldNameForChar))
							{
								cout << "Enter new char field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForChar, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForChar, ARRAY_SIZE);
								}
								cout << "Enter new char field value: ";
								cin.getline(databaseEntity[searchUserInput].charField, ARRAY_SIZE);
							}
							else if (fieldType == 1 && string(editFieldUserInput) == string(databaseEntity[x].fieldNameForInt))
							{
								cout << "Enter new int field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForInt, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForInt, ARRAY_SIZE);
								}
								cout << "Enter new int field value: ";
								while (!(cin >> databaseEntity[searchUserInput].intField) || cin.get() != '\n') {
									cout << "ERROR: Please enter integers only! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
							}
							else if (fieldType == 2 && string(editFieldUserInput) == string(databaseEntity[x].fieldNameForFloatOne))
							{
								cout << "Enter new float field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForFloatOne, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForFloatOne, ARRAY_SIZE);
								}
								cout << "Enter new float field value: ";
								while (!(cin >> databaseEntity[searchUserInput].floatFieldOne))
								{
									cout << "ERROR: Please enter floats only! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								};
							}
							else if (fieldType == 2 && string(editFieldUserInput) == string(databaseEntity[x].fieldNameForFloatTwo))
							{
								cout << "Enter new float field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForFloatTwo, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForFloatTwo, ARRAY_SIZE);
								}
								cout << "Enter new float field value: ";
								while (!(cin >> databaseEntity[searchUserInput].floatFieldTwo))
								{
									cout << "ERROR: Please enter floats only! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								};
							}
							else if (fieldType == 3 && string(editFieldUserInput) == string(databaseEntity[x].fieldNameForBool))
							{
								cout << "Enter new bool field name: ";
								cin.getline(databaseEntity[searchUserInput].fieldNameForBool, ARRAY_SIZE);
								while (cin.fail())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cout << "Please enter correct input value here! Now Try again: ";
									cin.getline(databaseEntity[searchUserInput].fieldNameForBool, ARRAY_SIZE);
								}
								cout << "Enter new bool field value (Enter 0 for False and 1 for True): ";
								while (!(cin >> databaseEntity[searchUserInput].boolField) || cin.get() != '\n') {
									cout << "ERROR: Please enter 0 or 1 only for Boolean ! Now Try Again: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
							}
						}
					}
				}
				else if (editMenuUserInput == 3)  			//3. Delete field in the entity
				{
					cin.ignore(INT_MAX, '\n');
					cout << "----------Edit Menu----------" << endl;
					cout << "2. Delete field" << endl;
					cout << "Which field you would like delete?";
					cin.getline(databaseEntity[searchUserInput].deleteField, ARRAY_SIZE);
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Please enter correct input value here! Now Try again: ";
						cin.getline(databaseEntity[searchUserInput].deleteField, ARRAY_SIZE);
					}

					bool findDelete = false;

					if (string(databaseEntity[searchUserInput].deleteField) == string(databaseEntity[searchUserInput].fieldNameForChar) ||
						string(databaseEntity[searchUserInput].deleteField) == string(databaseEntity[searchUserInput].fieldNameForInt) ||
						string(databaseEntity[searchUserInput].deleteField) ==
						string(databaseEntity[searchUserInput].fieldNameForFloatOne) ||
						string(databaseEntity[searchUserInput].deleteField) ==
						string(databaseEntity[searchUserInput].fieldNameForFloatTwo) ||
						string(databaseEntity[searchUserInput].deleteField) == string(databaseEntity[searchUserInput].fieldNameForBool))
					{
						findDelete = true;
					}

					if (findDelete == false)
					{
						cout << "Field does not exists in Database" << endl << endl;
					}

					if (string(databaseEntity[searchUserInput].editField) == string(databaseEntity[searchUserInput].fieldNameForChar))
					{

						databaseEntity[searchUserInput].fieldNameForChar[ARRAY_SIZE] = {};
						databaseEntity[searchUserInput].charField[ARRAY_SIZE] = {};
					}
					else if (string(databaseEntity[searchUserInput].editField) == string(databaseEntity[0].fieldNameForInt))
					{
						databaseEntity[searchUserInput].fieldNameForInt[ARRAY_SIZE] = {};
						databaseEntity[searchUserInput].intField = 0;

					}
					else if (string(databaseEntity[searchUserInput].editField) == string(databaseEntity[0].fieldNameForFloatOne))
					{
						databaseEntity[searchUserInput].fieldNameForFloatOne[ARRAY_SIZE] = {};
						databaseEntity[searchUserInput].floatFieldOne = 0.0;
					}
					else if (string(databaseEntity[searchUserInput].editField) ==
						string(databaseEntity[searchUserInput].fieldNameForFloatTwo))
					{

						databaseEntity[searchUserInput].fieldNameForFloatTwo[ARRAY_SIZE] = {};
						databaseEntity[searchUserInput].floatFieldTwo = 0.0;
					}
					else if (string(databaseEntity[searchUserInput].editField) == string(databaseEntity[0].fieldNameForBool))
					{
						databaseEntity[searchUserInput].fieldNameForBool[ARRAY_SIZE] = {};
						databaseEntity[searchUserInput].boolField = 0;
					}
					else
					{
						cout << "Invalid input. Please enter the field type option between 0 to 3." << endl;
					}

				}
				else if (editMenuUserInput == 4)  			//4. Go back to main menu
				{
				cout << "----------Edit Menu----------" << endl;
				cout << "4. Go back to main menu" << endl;
					break;
				}
				else
				{
					cout << "Invalid input. Please choose the options between 1 to 4." << endl;
				}
			}
		}
		else if (mainMenuUserInput == 3)  																	//3. Remove entity
		{
			cout << "---------------------Option 3------------------------" << endl;
			cout << "Please enter ID of the entity to remove: " << endl;

			cin.ignore(INT_MAX, '\n');
			cin >> removeUserInput;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter correct input value here! Now Try again: ";
				cin >> removeUserInput;
			}

			bool foundRemove = false;

			for (int x = 0; x < DATABASE_SIZE; x++)
			{
				if (removeUserInput == databaseEntity[x].id)
				{
					foundRemove = true;
				}
			}
			cout << "Removing entity ID ( " << removeUserInput << " )" << endl;
			if (foundRemove == false)
			{
				cout << "ID " << removeUserInput << " does not exists in Database" << endl << endl;
			}
			while (foundRemove == true)
			{
				databaseEntity[removeUserInput] = {};
				foundRemove = false;
			}
		}
		else if (mainMenuUserInput == 4)  																	//4. Print entity info
		{
			cout << "---------------------Option 4------------------------" << endl;
			cout << "Please enter ID of the entity to print: " << endl;

			cin.ignore(INT_MAX, '\n');
			cin >> printUserInput;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Please enter correct input value here! Now Try again: ";
				cin >> printUserInput;
			}

			bool foundPrint = false;

			for (int x = 0; x < DATABASE_SIZE; x++)
			{
				if (printUserInput == databaseEntity[x].id)
				{
					foundPrint = true;
				}
			}
			cout << "Printing entity ID ( " << printUserInput << " )" << endl;
			if (foundPrint == false)
			{
				cout << "ID " << printUserInput << " does not exists in Database" << endl << endl;
			}
			while (foundPrint == true)
			{
				if (string(databaseEntity[printUserInput].fieldNameForChar) != "" && string(databaseEntity[printUserInput].charField) != "")
				{
					cout << databaseEntity[printUserInput].fieldNameForChar << " : " << databaseEntity[printUserInput].charField << endl;
				}
				if (string(databaseEntity[printUserInput].fieldNameForInt) != "" && databaseEntity[printUserInput].intField != 0)
				{
					cout << databaseEntity[printUserInput].fieldNameForInt << " : " << databaseEntity[printUserInput].intField << endl;
				}
				if (string(databaseEntity[printUserInput].fieldNameForFloatOne) != "" && databaseEntity[printUserInput].floatFieldOne != 0.0f)
				{
					cout << databaseEntity[printUserInput].fieldNameForFloatOne << " : ";
					cout << fixed;
					cout << setprecision(1);
					cout << databaseEntity[printUserInput].floatFieldOne << endl;
				}
				if (string(databaseEntity[printUserInput].fieldNameForFloatTwo) != "" && databaseEntity[printUserInput].floatFieldTwo != 0.0f)
				{
					cout << databaseEntity[printUserInput].fieldNameForFloatTwo << " : ";
					cout << fixed;
					cout << setprecision(1);
					cout << databaseEntity[printUserInput].floatFieldTwo << endl;
				}
				if (string(databaseEntity[printUserInput].fieldNameForBool) != "")
				{
					cout << databaseEntity[printUserInput].fieldNameForBool << " : ";
					if (databaseEntity[printUserInput].boolField == true)
					{
						cout << "true" << endl;
					}
					else
					{
						cout << "false" << endl;
					}
				}

				foundPrint = false;
			}
		}
		else if (mainMenuUserInput == 5)  																	//5. Stop the program
		{
			cout << "---------------------Option 5: Stopping the program...------------------------" << endl;
			flag = false;
			exit(0);
		}
		else
		{
			cout << "Invalid input. Please choose the option between 1 to 5." << endl;
		}

		cout << endl << "What would you like to do next?" << endl;
		cout << "1. Add entity" << endl;
		cout << "2. Edit entity" << endl;
		cout << "3. Remove entity" << endl;
		cout << "4. Print entity info" << endl;
		cout << "5. Stop the program" << endl;

		cin >> mainMenuUserInput;
	}
	return 0;
}
