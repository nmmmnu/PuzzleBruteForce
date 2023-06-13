#include <cstdint>
#include <cstdio>
#include <array>

enum class Picture : uint8_t{
	M1,	// Mickey
	M2,
	D1,	// Mini (Dama)
	D2,
	G1,	// Goofy
	G2,
	P1,	// Pluto
	P2
};

struct Card{
	Picture	face[4 + 3] = {};

	constexpr Card(Picture p0, Picture p1, Picture p2, Picture p3){
		face[0] = p0;
		face[1] = p1;
		face[2] = p2;
		face[3] = p3;

		face[4] = p0;
		face[5] = p1;
		face[6] = p2;
	}

	constexpr auto const &operator[](size_t i) const{
		return face[i];
	}
};

constexpr auto cards = [](){
	using _ = Picture;

	return std::array<Card, 9>{
		Card{ _::M2, _::P2, _::D1, _::G1 },
		Card{ _::M2, _::D1, _::G1, _::P2 },
		Card{ _::D1, _::G2, _::M1, _::P2 },

		Card{ _::P1, _::D1, _::G2, _::M2 },
		Card{ _::D2, _::P1, _::G2, _::M1 },
		Card{ _::M2, _::D2, _::G1, _::P2 },

		Card{ _::G2, _::P1, _::M2, _::D2 },
		Card{ _::M1, _::G2, _::D1, _::P2 },
		Card{ _::M2, _::P1, _::D2, _::G1 }
	};
}();

constexpr bool cmp(Picture a, Picture b){
	using _ = Picture;

	return
		(a == _::M1 && b == _::M2) ||
		(a == _::D1 && b == _::D2) ||
		(a == _::G1 && b == _::G2) ||
		(a == _::P1 && b == _::P2) ||

		(a == _::M2 && b == _::M1) ||
		(a == _::D2 && b == _::D1) ||
		(a == _::G2 && b == _::G1) ||
		(a == _::P2 && b == _::P1)
	;
}

int main(){
	uint8_t r[9];
	uint8_t p[9];

	size_t pass = 0;
	size_t pass_c = 0;

	for(r[0] = 2; r[0] < 4; ++r[0])	// rotation
	for(r[1] = 0; r[1] < 4; ++r[1])
	for(r[2] = 0; r[2] < 4; ++r[2])
	for(r[3] = 0; r[3] < 4; ++r[3])
	for(r[4] = 0; r[4] < 4; ++r[4])
	for(r[5] = 0; r[5] < 4; ++r[5])
	for(r[6] = 0; r[6] < 4; ++r[6])
	for(r[7] = 0; r[7] < 4; ++r[7])
	for(r[8] = 0; r[8] < 4; ++r[8])

	for(p[0] = 0; p[0] < 9; ++p[0])	// permutation
		if constexpr(0 /* auto const _ = p[0]; _ == p[0] */)
			continue;
		else
			for(p[1] = 0; p[1] < 9; ++p[1])
				if (auto const _ = p[1]; _ == p[0])
					continue;
				else
					for(p[2] = 0; p[2] < 9; ++p[2])
						if (auto const _ = p[2]; _ == p[0] || _ == p[1])
							continue;
						else
							for(p[3] = 0; p[3] < 9; ++p[3])
								if (auto const _ = p[3]; _ == p[0] || _ == p[1] || _ == p[2])
									continue;
								else
									for(p[4] = 0; p[4] < 9; ++p[4])
										if (auto const _ = p[4]; _ == p[0] || _ == p[1] || _ == p[2] || _ == p[3])
											continue;
										else
											for(p[5] = 0; p[5] < 9; ++p[5])
												if (auto const _ = p[5]; _ == p[0] || _ == p[1] || _ == p[2] || _ == p[3] || _ == p[4])
													continue;
												else
													for(p[6] = 0; p[6] < 9; ++p[6])
														if (auto const _ = p[6]; _ == p[0] || _ == p[1] || _ == p[2] || _ == p[3] || _ == p[4] || _ == p[5])
															continue;
														else
															for(p[7] = 0; p[7] < 9; ++p[7])
																if (auto const _ = p[7]; _ == p[0] || _ == p[1] || _ == p[2] || _ == p[3] || _ == p[4] || _ == p[5] || _ == p[6])
																	continue;
																else
																	for(p[8] = 0; p[8] < 9; ++p[8])
																		if (auto const _ = p[8]; _ == p[0] || _ == p[1] || _ == p[2] || _ == p[3] || _ == p[4] || _ == p[5] || _ == p[6] || _ == p[7])
																			continue;
																		else{
		// ==============

		++pass;
		++pass_c;

		if (pass_c > 100'000'000){
			pass_c = 0;

			printf("%u %u %u %u %u %u %u %u %u | %u %u %u %u %u %u %u %u %u\n",
					r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8],
					p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]
			);
		}

		auto const c = cards;

		if (
			cmp(c[ p[0] ][ r[0] + 1 ], c[ p[1] ][ r[1] + 3 ])	&&	cmp( c[ p[1] ][ r[1] + 1 ], c[ p[2] ][ r[2] + 3 ])	&&	// row1
			cmp(c[ p[3] ][ r[3] + 1 ], c[ p[4] ][ r[4] + 3 ])	&&	cmp( c[ p[4] ][ r[4] + 1 ], c[ p[5] ][ r[5] + 3 ])	&&	// row2
			cmp(c[ p[6] ][ r[6] + 1 ], c[ p[7] ][ r[7] + 3 ])	&&	cmp( c[ p[7] ][ r[7] + 1 ], c[ p[8] ][ r[8] + 3 ])	&&	// row3
			cmp(c[ p[0] ][ r[0] + 2 ], c[ p[3] ][ r[3] + 0 ])	&&	cmp( c[ p[3] ][ r[3] + 2 ], c[ p[6] ][ r[6] + 0 ])	&&	// col1
			cmp(c[ p[1] ][ r[1] + 2 ], c[ p[4] ][ r[4] + 0 ])	&&	cmp( c[ p[4] ][ r[4] + 2 ], c[ p[7] ][ r[7] + 0 ])	&&	// col2
			cmp(c[ p[2] ][ r[2] + 2 ], c[ p[5] ][ r[5] + 0 ])	&&	cmp( c[ p[5] ][ r[5] + 2 ], c[ p[8] ][ r[8] + 0 ])	&&	// col3

			true
		){
			printf("Solved!!!! %zu\n", pass);

			printf("%u %u %u %u %u %u %u %u %u | %u %u %u %u %u %u %u %u %u\n",
					r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8],
					p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]
			);

			return 0;
		}
	}



	printf("NOT Solved!!!! %zu\n", pass);

	printf("%u %u %u %u %u %u %u %u %u | %u %u %u %u %u %u %u %u %u\n",
			r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8],
			p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]
	);

	return 1;
};

