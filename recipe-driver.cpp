/* 
Programming Assignment #4
Filename: recipe-driver.cpp
*/

#include "recipe.h"

int main() {
	cout << "Let's build a Recipe Book!" << endl;
	
	// Temporary variables used for entering data into functions, etc
	string temp1, temp2, temp3, temp4;
	int temp, temp0;
	Recipe recipe;
	RecipeStep recipestep;
	
	// Asks user for Recipe Book title and uses the conversion constructor (that takes in a string)
	cout << "What is the title of your Recipe Book?" << endl;
	getline(cin, temp1);
	
	RecipeBook recipebook(temp1);
	
	// Goes through creating the 7 recipes and the steps for each of the 7 recipes
	cout << "Let's make seven recipes!" << endl;
	
	for (int i = 0; i < 7; i++) {
		cout << "What is the title of Recipe #" << i + 1 << '?' << endl;
		getline(cin, temp1);
		cout << "What is the description of Recipe #" << i + 1 << '?' << endl;
		getline(cin, temp2);
		
		recipe.setTitle(temp1);
		recipe.setDescription(temp2);
		recipe.setID(i + 1);
		recipebook.Create(recipe);
		
		int numSteps;
		cout << "How many steps would you like for Recipe #" << i + 1 << '?' << endl;
		cin >> numSteps;
		cin.ignore();
		
		for (int j = 0; j < numSteps; j++) {
			cout << "What is the header of RecipeStep #" << j + 1 << " in Recipe #" << i + 1 << '?' << endl;
			getline(cin, temp3);
			cout << "What is the description of RecipeStep #" << j + 1 << " in Recipe #" << i + 1 << '?' << endl;
			getline(cin, temp4);
			
			recipestep.setHeader(temp3);
			recipestep.setDescription(temp4);
			recipestep.setSequenceNumber(j + 1);
			recipebook.getRecipes()[i].Create(recipestep);
		}
	}
	
	cout << "Here is your Recipe Book so far" << endl;
	recipebook.Print();
	
	// Demonstrates both delete functions working (both for RecipeBook and Recipe)
	cout << "Which recipe would you like to delete (enter ID number)?" << endl;
	cin >> temp;
	temp -= 1;
	
	recipebook.Delete(recipebook.getRecipes()[temp]);
	
	cout << "Here is the updated Recipe Book" << endl;
	recipebook.Print();
	
	cout << "Which recipe would you like to delete step(s) from?" << endl;
	cin >> temp;
	temp -= 1;
	recipebook.getRecipes()[temp].Print();
	cout << "How many steps would you like to delete from Recipe #" << temp + 1 << '?' << endl;
	cin >> temp0; 
	
	for (int i = 0; i < temp0; i++) {
		int numStep;
		recipebook.getRecipes()[temp].Print();
		cout << "Which step would you like to delete?" << endl;
		cin >> numStep;
		numStep -= 1;
		recipebook.getRecipes()[temp].Delete(recipebook.getRecipes()[temp].getSteps()[numStep]);
	}
	
	cout << "Here is your Recipe Book" << endl;
	recipebook.Print();
	
	// Demonstrates both update functions working (both for RecipeBook and Recipe)
	cout << "Which recipe would you like to update (enter number)?" << endl;
	cin >> temp;
	cin.ignore();
	
	cout << "What is the new title of Recipe #" << temp << '?' << endl;
	getline(cin, temp1);
	cout << "What is the description of Recipe #" << temp << '?' << endl;
	getline(cin, temp2);
		
	temp -= 1;
	
	recipebook.updateRecipe(recipebook.getRecipes()[temp], temp1, temp2);
	
	cout << "Here is the updated Recipe Book" << endl;
	recipebook.Print();
	
	cout << "Which recipe would you like to update step(s) from?" << endl;
	cin >> temp;
	temp -= 1;
	recipebook.getRecipes()[temp].Print();
	cout << "How many steps would you like to update from Recipe #" << temp + 1 << '?' << endl;
	cin >> temp0; 
	
	for (int i = 0; i < temp0; i++) {
		int numStep;
		recipebook.getRecipes()[temp].Print();
		cout << "Which step would you like to update?" << endl;
		cin >> numStep;
		cin.ignore();
		
		cout << "What is the new header of Recipe Step #" << numStep << " in Recipe #" << temp + 1 << '?' << endl;
		getline(cin, temp1);
		cout << "What is the description of Recipe Step #" << numStep << " in Recipe #" << temp + 1 << '?' << endl;
		getline(cin, temp2);
		
		numStep -= 1;
		recipebook.getRecipes()[temp].updateStep(recipebook.getRecipes()[temp].getSteps()[numStep], temp1, temp2);
	}
	
	// Prints book at end
	cout << "Your final Recipe Book" << endl;
	cout << recipebook;
	
	// Demonstrates both the copy constructor and deep copy assignment operator overload working
	cout << "Testing copy constructor" << endl;
	RecipeBook recipebook2 = recipebook;
	cout << recipebook2;
	
	RecipeBook recipebook3;
	cout << "Testing deep copy assignment operator overload" << endl;
	recipebook3 = recipebook2;
	cout << recipebook3;
		
}