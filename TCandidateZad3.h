#pragma once
#include "TCandidate.h"

class TCandidateZad3 : public TCandidate {
public:
    TCandidateZad3();
    void rate() override;
    void init_vector() override;
    TCandidate* create_new() const override;
    TCandidate* create_copy() const override;
};