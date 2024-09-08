/* 
Programming Assignment #4
Filename: recipe.h
*/

#include <iostream>
#include <string>
using namespace std;

class RecipeStep {
	// Insertion operator overload
	friend ostream& operator<<(ostream& o, const RecipeStep& r);
	private:
		// Private data members for each Recipe Step
		int sequenceNumber;
		string header, description;
	public:
		// Constructors
		RecipeStep();
	
		// Getters
		int getSequenceNumber() const;
		
		// Setters
		void setSequenceNumber(int sequenceNumber);
		void setHeader(string header);
		void setDescription(string description);
};

class Recipe {
	// Insertion operator overload
	friend ostream& operator<<(ostream& o, const Recipe& r);
	private:
		// A pointer to a RecipeStep, called steps
		RecipeStep* steps;
		// Private data members useful for tracking size/capacity of the dynamically created array created in the .cpp file
		// ID useful for finding a particular recipe within the book
		int size, capacity, id;
		// Title and description of recipe
		string title, description;
	public:
		// Default constructor
		Recipe();
		// copy constructor - #1 Rule of Three
		Recipe(const Recipe& r);	
		// destructor - #3 Rule of Three
		~Recipe();
		
		// Deep copy assignment operator overload - #2 Rule of Three
		Recipe& operator=(const Recipe& r);
		
		// Getters
		int getId() const;
		
		// Setters
		void setTitle(string title);
		void setDescription(string description);
		void setID(int id);
		
		// Find a RecipeStep in the Recipe
		int findRecipeStep(const RecipeStep& r) const;
		
		// CRUD
		void Create(const RecipeStep& r);
		// For "R" in CRUD
		RecipeStep* getSteps();
		void updateStep(const RecipeStep& r, string stepHeader, string stepDesc);
		void Delete(const RecipeStep& r);
		void Print() const;
};

class RecipeBook {
	// Insertion operator overload
	friend ostream& operator<<(ostream& o, const RecipeBook& r);
	private:
		// A pointer to a Recipe, called recipes
		Recipe* recipes;
		// Private data members useful for tracking size/capacity of the dynamically created array created in the .cpp file
		int size, capacity;
		// Title of Book
		string title;
	public:
		// Default constructor
		RecipeBook();
		// Conversion constructor
		RecipeBook(string title);
		// Copy constructor - #1 Rule of Three
		RecipeBook(const RecipeBook& r);	
		// Destructor - #3 Rule of Three
		~RecipeBook();
		
		// Deep copy assignment operator overload - #2 Rule of Three
		RecipeBook& operator=(const RecipeBook& r);
		
		// Find a Recipe in the RecipeBook
		int findRecipe(const Recipe& recipe) const;
		
		// CRUD
		void Create(const Recipe& r);
		// For "R" in CRUD
		Recipe* getRecipes();
		void updateRecipe(const Recipe& r, string recipeTitle, string recipeDesc);
		void Delete(const Recipe& r);
		void Print() const;
		
};