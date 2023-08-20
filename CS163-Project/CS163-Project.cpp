/*******************************************************************************************
*
*   raylib [shapes] example - Draw raylib logo using basic shapes
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "System.h"
#include "Dictionary.h"
#include <chrono>
#include "UI/Other.h"

int main(void)
{
    System system;
    system.Construct();
    system.Draw();
    system.Destruct();


    //Dictionary d;
    //auto start = chrono::high_resolution_clock::now();
    //d.buildFromOrigin();
    //d.addNewWord(1, "A", "The first letter of the English and of many other alphabets. The capital A of the alphabets of Middle and Western Europe, as also the small letter (a), besides the forms in Italic, black letter, etc., are all descended from the old Latin A, which was borrowed from the Greek Alpha, of the same form; and this was made from the first letter (/) of the Phoenician alphabet, the equivalent of the Hebrew Aleph, and itself from the Egyptian origin. The Aleph was a consonant letter, with a guttural breath sound that was not an element of Greek articulation; and the Greeks took it to represent their vowel Alpha with the a sound, the Phoenician alphabet having no vowel symbols.");
 //   d.addNewWord(1, "A", "Of.");
 //   d.addNewWord(1, "On", "Of.");
 //   auto tmp = d.searchHashDefinition("Of.", 1);
 //   for(int i = 0; i < tmp.size(); i++)
	//{
	//	cout << tmp[i][0] << endl;
	//}
    //d.build();
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    //cout << "Time taken by loading data: " << duration.count() << " milliseconds" << endl;
    //cout << d.isFavourite("hello") << endl;
    //d.save();

    return 0;
}