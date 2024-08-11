#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Define the Book struct directly in this file
struct Book {
    std::string title;
    std::string author;
    int year;
    int ID;
    std::string publisher;
};

// Unit Tests
TEST(BookTest, Book1) {
    Book book1;
    book1.title = "World";
    book1.author = "Me";
    book1.year = 1985;
    book1.ID = 12;
    book1.publisher = "Venezia";

    EXPECT_EQ(book1.title, "World");
    EXPECT_EQ(book1.author, "Me");
    EXPECT_EQ(book1.year, 1985);
    EXPECT_EQ(book1.ID, 12);
    EXPECT_EQ(book1.publisher, "Venezia");
}

TEST(BookTest, Book2) {
    Book book2;
    book2.title = "Friuli";
    book2.author = "MT";
    book2.year = 1946;
    book2.ID = 22;
    book2.publisher = "Savorgnano";

    EXPECT_EQ(book2.title, "Friuli");
    EXPECT_EQ(book2.author, "MT");
    EXPECT_EQ(book2.year, 1946);
    EXPECT_EQ(book2.ID, 22);
    EXPECT_EQ(book2.publisher, "Savorgnano");
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}