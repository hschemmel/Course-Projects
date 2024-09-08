/*
Programming Assignment #4
Filename: recipe.cpp
*/

#include "recipe.h"
//==========================RecipeStep

// Insertion operator overload for RecipeStep
ostream& operator<<(ostream& o, const RecipeStep& r) {
	o << "\t" << r.sequenceNumber << ". " << r.header << ": " << r.description << endl;
	return o;
}

// Default constructor for RecipeStep
RecipeStep::RecipeStep() {
	// Just initializes everything to something random according to the appropriate types
	sequenceNumber = 1;
	header = "Mix";
	description = "Mix the veggies and the eggs";
}
	
// Getter for RecipeStep
int RecipeStep::getSequenceNumber() const {
	return sequenceNumber;
}
	
// Setters for RecipeStep
void RecipeStep::setSequenceNumber(int sequenceNumber) {
	this->sequenceNumber = sequenceNumber;
}
void RecipeStep::setHeader(string header) {
	this->header = header;
}
void RecipeStep::setDescription(string description) {
	this->description = description;
}

//==========================Recipe

// Insertion operator overload for Recipe
ostream& operator<<(ostream& o, const Recipe& r) {
	// First prints title and description
	o << r.id << ". " << r.title << ": " << r.description << endl;
	// Loops through everything in the array of type RecipeStep called steps
	for (int i = 0; i < r.size; i++) {
		o << r.steps[i] << endl;
	}
	return o;
}

// Default constructor for Recipe
Recipe::Recipe() {
	size = 0;
	capacity = 5;
	// Just initializes the below to something random according to the appropriate types
	id = 0;
	title = "Recipe1";
	description = "Description1";
	
	// Creates a dynamically created array of type RecipeStep
	steps = new RecipeStep[capacity];
}
		
// Copy constructor - #1 Rule of Three
Recipe::Recipe(const Recipe& r) {
	size = r.size;
	capacity = r.capacity;
	id = r.id;
	title = r.title;
	description = r.description;
	
	steps = new RecipeStep[capacity];
	
	// Only need to copy everything up to size because those are the only array slots with actual data
	for (int i = 0; i < size; i++) {
		steps[i] = r.steps[i];
	}
}

// Destructor - #3 Rule of Three
Recipe::~Recipe() {
	delete [] steps;
}
		
// Deep copy assignment operator overload - #2 Rule of Three
Recipe& Recipe::operator=(const Recipe& r) {
	// Don't want to go through the below copying if there is a line of code for something equals itself
	if (this != &r) {
		size = r.size;
		capacity = r.capacity;
		id = r.id;
		title = r.title;
		description = r.description;
		
		// Want to delete the old array before making a new one and copying over everything that is in r.steps
		delete [] steps;
		
		steps = new RecipeStep[capacity];
	
		// Only need to copy everything up to size because those are the only array slots with actual data
		for (int i = 0; i < size; i++) {
			steps[i] = r.steps[i];
		}
	}
	
	// Need to dereference this before returning
	return *this;
}

// Getter for Recipe id
int Recipe::getId() const {
	return id;
}

// Setters for Recipe
void Recipe::setTitle(string title) {
	this->title = title;
}

void Recipe::setDescription(string description) {
	this->description = description;
}

void Recipe::setID(int id) {
	this->id = id;
}

// To find the index at which a particular recipe is at
int Recipe::findRecipeStep(const RecipeStep& r) const {
	int index; 
	
	// Uses the sequence number to find the index of the item
	for(int i = 0; i < size; i++) {
		if(steps[i].getSequenceNumber() == r.getSequenceNumber()) {
			index = i;
		}
	}
	return index;
}

void Recipe::Create(const RecipeStep& r) {
	// Only need to go through growth algorithm if current array is full
	if (size >= capacity) {
		RecipeStep* tmp = new RecipeStep[capacity + 1];

		// size is the size of the initial array because those are the only array slots with actual data		
		for (int i = 0; i < size; i++) {
			// Automatic assignment operator, shallow copy
			tmp[i] = steps[i];
		}
		
		delete [] steps;
		
		steps = tmp;
		
		// Array can now hold one more slot
		capacity = capacity + 1;
	}
	// Adding in the new recipe and incrementing size now that the array has one more item
	steps[size++] = r;
}

// Returns the private data member, steps
RecipeStep* Recipe::getSteps() {
	return steps;
}

void Recipe::updateStep(const RecipeStep& r, string stepHeader, string stepDesc) {
	int index = findRecipeStep(r);
	
	steps[index].setHeader(stepHeader);
	steps[index].setDescription(stepDesc);
}

void Recipe::Delete(const RecipeStep& r) {
	/* Finds the index of the item the user wants removed
	and shifts over all items at a higher index to the left by one 
	to remove it so there are no gaps in the array */
	int index = findRecipeStep(r);
	
	for (int i = index; i < size - 1; i++) {
		steps[i] = steps[i+1];
		steps[i].setSequenceNumber(i+1);
	}
	
	// Decrements size by one because an item was removed
	size--;
}

void Recipe::Print() const {
	// Uses insertion operator overload to print
	// First prints title and description
	cout << title << ": " << description << endl;
	
	// Goes through steps
	for (int i = 0; i < size; i++) {
		cout << steps[i] << endl;
	}
}

//==========================RecipeBook

// Insertion operator overload for RecipeBook
ostream& operator<<(ostream& o, const RecipeBook& r) {
	// Loops through everything in the array of type Recipe called recipes
	for (int i = 0; i < r.size; i++) {
		o << r.recipes[i] << endl;
	}
	return o;
}

// Default constructor for Recipe Book
RecipeBook::RecipeBook() {
	capacity = 5;
	size = 0;
	// Initializes title to something random according to the appropriate type (string)
	title = "Recipe Book";
	
	// Creates a dynamically created array of type Recipe
	recipes = new Recipe[capacity];
}

// Conversion constructor for RecipeBook
RecipeBook::RecipeBook(string title) {
	capacity = 5;
	size = 0;
	this->title = title;
	
	// Creates a dynamically created array of type Recipe
	recipes = new Recipe[capacity];
}	
		
// Copy constructor - #1 Rule of Three
RecipeBook::RecipeBook(const RecipeBook& r) {
	size = r.size;
	capacity = r.capacity;
	title = r.title;
	
	recipes = new Recipe[capacity];

	// Only need to copy everything up to size because those are the only array slots with actual data
	for (int i = 0; i < size; i++) {
		recipes[i] = r.recipes[i];
	}
	
}

// Destructor - #3 Rule of Three
RecipeBook::~RecipeBook() {
	delete [] recipes;
}
		
// Deep copy assignment operator overload - #2 Rule of Three
RecipeBook& RecipeBook::operator=(const RecipeBook& r) {
	// Don't want to go through the below copying if there is a line of code for something equals itself
	if (this != &r) {
		size = r.size;
		capacity = r.capacity;
		title = r.title;
		
		// Want to delete the old array before making a new one and copying over everything that is in r.recipes
		delete [] recipes;
		
		recipes = new Recipe[capacity];
		
		// Only need to copy everything up to size because those are the only array slots with actual data
		for (int i = 0; i < size; i++) {
			recipes[i] = r.recipes[i];
		}
	}
	
	// Need to dereference this before returning
	return *this;
}

// To find the index at which a particular recipe is at
int RecipeBook::findRecipe(const Recipe& recipe) const {
	int index;
	
	// Uses the id to find the index of the item
	for(int i = 0; i < size; i++) {
		if(recipes[i].getId() == recipe.getId()) {
			index = i;
		}
	}
	return index;
}

void RecipeBook::Create(const Recipe& r) {
	// Only need to go through growth algorithm if current array is full
	if (size >= capacity) {
		Recipe* tmp = new Recipe[capacity + 1];

		// size is the size of the initial array because those are the only array slots with actual data		
		for (int i = 0; i < size; i++) {
			// Automatic assignment operator, shallow copy
			tmp[i] = recipes[i];
		}
		
		delete [] recipes;
		
		recipes = tmp;
		
		// Array can now hold one more slot
		capacity = capacity + 1;
	}
	// Adding in the new recipe and incrementing size now that the array has one more item
	recipes[size++] = r;
}

// Returns private data member, recipes
Recipe* RecipeBook::getRecipes() {
	return recipes;
}

void RecipeBook::updateRecipe(const Recipe& r, string recipeTitle, string recipeDesc) {
	int index = findRecipe(r);
	
	recipes[index].setTitle(recipeTitle);
	recipes[index].setDescription(recipeDesc);
}

void RecipeBook::Delete(const Recipe& r) {
	/* Finds the index of the item the user wants removed
	and shifts over all items at a higher index to the left by one 
	to remove it so there are no gaps in the array */
	int index = findRecipe(r);
	
	for (int i = index; i < size - 1; i++) {
		recipes[i] = recipes[i+1];
		recipes[i].setID(i+1);
	}
	
	size--;
}

void RecipeBook::Print() const {
	// Uses insertion operator overload to print
	// First prints title
	cout << title << endl;
	
	// Goes through recipes
	for (int i = 0; i < size; i++) {
		cout << recipes[i] << endl;
	}
}