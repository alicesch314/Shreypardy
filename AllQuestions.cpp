// ********************
//     Preamble
// ********************

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// ********************
//      Constants
// ********************

static const int noq = 30; // number of questions in deck of quesitons

static const char *questions[noq] = {
"If Shrey could have a lifetime supply of an item, what would it be?",
"What is Shrey's favourite colour?",
"What is Shrey most scared of?",
"Where is Shrey's dream vacation?",
"What food does Shrey want to try the most?",
"What is Shrey's favourite game?",
"What is Shrey's secret passion?",
"If Shrey got arrested, what crime would he have committed?",
"How could one seduce Shrey?",
"What is Shrey's catch phrase?",
"What is Shrey's favourite book?",
"How many times per day does Shrey take a shit?",
"If Shrey was an alcoholic drink, what drink would he be?",
"What is Shrey's spirit animal?",
"What does Shrey need most?",
"If Shrey had one wish, what would it be?",
"What is Shrey's dream job?",
"Who is Shrey's role model?",
"What makes Shrey laugh the most?",
"What would Shrey's theme song be?",
"What is Shrey's greatest pet peeve?",
"How many pairs of pants does Shrey own?",
"What is the first thing Shrey would buy if he won the lottery?",
"If Shrey could meet anyone from the past, who would it be?",
"What is Shrey's best talent?",
"If Shrey had a warning label, what would it say?",
"What is Shrey's favourite ice cream flavour?"
"What is Shrey's favouirte genre of music?",
"What is Shrey's weirdest habit?",
"If Shrey was a youtuber, what kind of videos would he make?"
};

static const char *values[noq] = {
"2",
"1",
"2",
"0.5",
"0.5",
"1",
"3",
"1",
"2",
"1",
"0.5",
"1",
"1",
"1",
"3",
"2",
"1",
"1",
"2",
"1",
"2",
"3",
"0.5",
"1",
"2",
"1",
"0.5",
"0.5",
"1",
"3"
};

