/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Errors/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_ERRORS_ERRORCONDITION_H_
#define _ISHIKO_ERRORS_ERRORCONDITION_H_

#include "ErrorCategory.h"
#include <ostream>

namespace Ishiko
{

class ErrorCondition
{
public:
    ErrorCondition() noexcept;
    ErrorCondition(int value, const ErrorCategory& category) noexcept;

    explicit operator bool() const noexcept;
    bool operator!() const noexcept;

    int value() const noexcept;
    const ErrorCategory& category() const noexcept;

    void fail(int value, const ErrorCategory& category) noexcept;
    void succeed() noexcept;

private:
    int m_value;
    const ErrorCategory* m_category;
};

std::ostream& operator<<(std::ostream& os, const ErrorCondition& condition);

}

#endif
