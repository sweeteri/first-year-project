#include "menu_items.hpp"

namespace IBusko {
	const GoBackItem LONG_GO_BACK("0 - Выйти в предыдущее меню", &STUDY_LONG);
	const LongAdditionItem LONG_ADDITION("1 - Заниматься сложение", &STUDY_LONG);
	const LongSubtractionItem LONG_SUBTRACTION("2 - Заниматься вычитанием", &STUDY_LONG);
	const LongSubtractionItem LONG_MULTIPLICATION("3 - Заниматься умножением", &STUDY_LONG);
	const LongDivisionItem LONG_DIVISION("4 - Заниматься делением", &STUDY_LONG);
	namespace {
		const MenuItem* const long_children[] = {
			&LONG_GO_BACK,
			&LONG_ADDITION,
			&LONG_SUBTRACTION,
			&LONG_MULTIPLICATION,
			&LONG_DIVISION
		};
		const int long_size = sizeof(long_children) / sizeof(long_children[0]);
	}
	
	const GoBackItem COMPLEX_GO_BACK("0 - Выйти в предыдущее меню", &STUDY_COMPLEX);
	namespace {
		const MenuItem* const complex_children[] = {
			&COMPLEX_GO_BACK
		};
		const int complex_size = sizeof(complex_children) / sizeof(complex_children[0]);
	}

    const GoBackItem SCHOOL_GO_BACK("0 - Выйти в предыдущее меню", &STUDY_SCHOOL);
    const SchoolDevisionItem SCHOOL_DIVISION("1 - Заниматься делением целых чисел", &STUDY_SCHOOL);
    namespace {
        const MenuItem* const school_children[] = {
                &SCHOOL_GO_BACK,
                &SCHOOL_DIVISION,
        };
        const int school_size = sizeof(school_children) / sizeof(school_children[0]);
    }

	const GoBackItem STUDY_GO_BACK("0 - Выйти в главное меню", &STUDY);
	const MenuItem STUDY_LONG(
		"1 - Заниматься длинной арифметикой", 
		&STUDY,
		long_children,
		long_size
	);
	const MenuItem STUDY_COMPLEX(
		"2 - Заниматься арифметикой комплексных чисел", 
		&STUDY,
		complex_children,
		complex_size
	);
    const MenuItem STUDY_SCHOOL(
            "3 - Заниматься школьной арифметикой",
            &STUDY,
            school_children,
            school_size
    );



	
	namespace {
		const MenuItem* const study_children[] = {
			&STUDY_GO_BACK,
			&STUDY_LONG,
			&STUDY_COMPLEX,
            &STUDY_SCHOOL,
		};
		const int study_size = sizeof(study_children) / sizeof(study_children[0]);
	}
	
	const MenuItem STUDY("1 - Хочу учиться математике!", &MAIN, study_children, study_size);
	const ExitItem EXIT("0 - Я лучше пойду полежу...", &MAIN);

	namespace {
		const MenuItem* const main_children[] = {
			&EXIT,
			&STUDY
		};
		const int main_size = sizeof(main_children) / sizeof(main_children[0]);
	}

	const MenuItem MAIN(main_children, main_size);	
}
