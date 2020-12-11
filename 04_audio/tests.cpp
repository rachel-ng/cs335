#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp> 
#include "AudioProcessor.h" 
#include "AudioProcessor.cpp"
#include <stdexcept>
#include <vector>


BOOST_AUTO_TEST_CASE(compress_one){  
    AudioProcessor processor; 
    std::vector<short> audio={1, 4, 25, 15, 0, -7, -40, 10};
    std::vector<short> expected_value =  {1, 4, 20, 13, 0, -7, -30, 10};
    BOOST_ASSERT(expected_value == processor.Compress(audio, 10, 1.5));
}

BOOST_AUTO_TEST_CASE(compress_two){  
    AudioProcessor processor; 
    std::vector<short> audio={1, 4, 25, 15, 0, -7, -40, 10};
    BOOST_CHECK_THROW(processor.Compress(audio, 10, .9), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compress_three){  
    AudioProcessor processor; 
    std::vector<short> audio={1, 4, 25, 15, 0, -7, -40, 10};
    BOOST_CHECK_THROW(processor.Compress(audio, -1, 12), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(compress_four){  
    AudioProcessor processor; 
    std::vector<short> audio={};
    std::vector<short> expected_value =  {};
    BOOST_ASSERT(expected_value == processor.Compress(audio, 10, 1.5));
}

BOOST_AUTO_TEST_CASE(cut_out_silence_one){  
    AudioProcessor processor; 
    std::vector<short> audio={1, -3, 10, 25, 56, -1, -2, -16, -20, -8, -1, 1, 7, 12};
    std::vector<short> expected_value = {25, 56, -1, -2, -16, -20, 12};
    BOOST_ASSERT(expected_value == processor.CutOutSilence(audio, 10, 3));
}

BOOST_AUTO_TEST_CASE(cut_out_silence_two){  
    AudioProcessor processor; 
    std::vector<short> audio={1,2,3,4,5,6,7,7,8,8,9,-1,-2,-3,-4,-5,-6,-7,-8,-9};
    std::vector<short> expected_value = {};
    BOOST_ASSERT(expected_value == processor.CutOutSilence(audio, 10, 3));
}

BOOST_AUTO_TEST_CASE(cut_out_silence_three){  
    AudioProcessor processor; 
    std::vector<short> audio= {};
    std::vector<short> expected_value = {};
    BOOST_ASSERT(expected_value == processor.CutOutSilence(audio, 10 , 3));
}

BOOST_AUTO_TEST_CASE(cut_out_silence_four){  
    AudioProcessor processor; 
    std::vector<short> audio= {};
    BOOST_CHECK_THROW(processor.CutOutSilence(audio, -1, 12), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(cut_out_silence_five){  
    AudioProcessor processor; 
    std::vector<short> audio= {};
    BOOST_CHECK_THROW(processor.CutOutSilence(audio, 1, 0 ), std::invalid_argument);
}


BOOST_AUTO_TEST_CASE(stretch_twice_one){  
    AudioProcessor processor; 
    std::vector<short> audio= {1, 4, 23, -2, -28, 10 };
    std::vector<short> expected_value = {1, 3, 4, 14, 23, 11, -2, -15, -28, -9, 10};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_two){  
    AudioProcessor processor; 
    std::vector<short> audio= {-1, -4, -23, -2, -28, -10 };
    std::vector<short> expected_value = {-1, -3, -4, -14, -23, -13, -2, -15, -28, -19, -10};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_three){  
    AudioProcessor processor; 
    std::vector<short> audio= {-1};
    std::vector<short> expected_value = {-1};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_four){  
    AudioProcessor processor; 
    std::vector<short> audio= {-1,-4};
    std::vector<short> expected_value = {-1,-3,-4};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_five){  
    AudioProcessor processor; 
    std::vector<short> audio= {-1,-4,1};
    std::vector<short> expected_value = {-1,-3,-4,-2, 1};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_six){  
    AudioProcessor processor; 
    std::vector<short> audio= {};
    std::vector<short> expected_value = {};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_seven){  
    AudioProcessor processor; 
    std::vector<short> audio= {0,0};
    std::vector<short> expected_value = {0,0,0};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(stretch_twice_eight){  
    AudioProcessor processor; 
    std::vector<short> audio= {0,0,0};
    std::vector<short> expected_value = {0,0,0,0,0};
    BOOST_ASSERT(expected_value == processor.StretchTwice(audio));
}

BOOST_AUTO_TEST_CASE(normalize_one){  
    AudioProcessor processor; 
    std::vector<short> audio= {-1, -30, 3, 15, 16, -7};
    std::vector<short> expected_value = {-1, -20, 2, 10, 11, -5};
    BOOST_ASSERT(expected_value == processor.Normalize(audio, 20));
}

BOOST_AUTO_TEST_CASE(normalize_two){  
    AudioProcessor processor; 
    std::vector<short> audio= {1, 3, -2, 5, -4, 0}; 
    std::vector<short> expected_value = {2, 6, -4, 10, -8, 0};
    BOOST_ASSERT(expected_value == processor.Normalize(audio, 10));
}

BOOST_AUTO_TEST_CASE(normalize_three){  
    AudioProcessor processor; 
    std::vector<short> audio= {1, 3, -2, 5, -4, 0}; 
    BOOST_CHECK_THROW(processor.Normalize(audio, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(normalize_four){  
    AudioProcessor processor; 
    std::vector<short> audio= {};
    std::vector<short> expected_value = {};
    BOOST_ASSERT(expected_value == processor.Normalize(audio, 20));
}

BOOST_AUTO_TEST_CASE(normalize_five){  
    AudioProcessor processor; 
    std::vector<short> audio= {0,0,0,0};
    std::vector<short> expected_value = {0,0,0,0};
    BOOST_ASSERT(expected_value == processor.Normalize(audio, 20));
}
