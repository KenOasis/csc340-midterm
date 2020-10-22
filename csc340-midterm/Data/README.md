#  Data documentation

## "data.csv" file is the raw data set in csv file format which is from the [kaggle.com](https://www.kaggle.com/rush4ratio/video-game-sales-with-ratings)

## The class **Game**, **Sales**, **Scores** are basic data structure to store the data in memories from the dataset (Do not worry about private field "id")
- Game
    ```Java
    {
        string: gameName
        string: platform
        int: yearOfRelease
        string: genre
        string: publisher
        Sales:
            double: NASales
            double: EUSales
            double: JPSales
            double: otherSales
            double:globalSales;
        Scores:
            int: criticScore
            int: criticCount
            double: userScore
            int: userCount
        // and a series of accessors of fields
        // and a printInfo and overloaded operator<< to print the info 
    }
   ```


## Utilities class is the basic utilites to read data from .csv file and store in a collection of object **Game** (in a vector form)
- Utilities
    ```Java
    {
        // function to load(read) file to the class, you have to call it explicitly to load the file by the given filepath
        LoadFile(string filepath);
        
        // function to return all the games in a vector
        vector<Game> getAllGames() const;
        
        // this form of function return a vector of Game from the whole
        // dataset by the given FIELD_VALUE of the FIELD
        vector<Game> getGamesBy_FIELD_(FIELD_VALUE) const;
        
        // this form of function return a vector of Game from the given collection (vector) of Game by the given FIELD_VALUE of FIELD
        vector<Game> getGamesBy_FIELD_(vector<Game>, FIELD_VALUE) const;
        
        // and a printALLGames to print all games in dataset 
    }
   ``` 
## In fact, the methods in utilities is similar to  the filter function of the spreadsheet. You can find a example in a main file.
