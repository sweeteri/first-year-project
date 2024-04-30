#pragma once

#include "exit_item.hpp"
#include "goback_item.hpp"

#include "long_addition_item.hpp"
#include "long_subtraction_item.hpp"
#include "long_multiplication_item.hpp"
#include "long_division_item.hpp"
#include "school_division_item.hpp"

namespace IBusko {
    extern const MenuItem MAIN;

    extern const MenuItem STUDY;
    extern const ExitItem EXIT;
	
    extern const MenuItem STUDY_LONG;
    extern const MenuItem STUDY_COMPLEX;
    extern const MenuItem STUDY_SCHOOL;
    extern const GoBackItem STUDY_GO_BACK;
	
    extern const LongAdditionItem LONG_ADDITION;
    extern const LongSubtractionItem LONG_SUBTRACTION;
    extern const LongSubtractionItem LONG_MULTIPLICATION;
	  extern const LongDivisionItem LONG_DIVISION;
    extern const GoBackItem LONG_GO_BACK;

    extern const SchoolDevisionItem SCHOOL_DIVISION;

    extern const GoBackItem COMPLEX_GO_BACK;
}

