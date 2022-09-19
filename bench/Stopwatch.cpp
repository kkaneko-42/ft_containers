#include "Stopwatch.hpp"

Stopwatch::Stopwatch( void )
{
    try
    {
        reset();
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

Stopwatch::Stopwatch( const Stopwatch& other )
{
    *this = other;
}

Stopwatch::~Stopwatch( void ) {}

Stopwatch& Stopwatch::operator=( const Stopwatch& other )
{
    if (this != &other)
    {
        start_time_ = other.start_time_;
        stop_time_ = other.stop_time_;
        is_running_ = other.is_running_;
    }
    return (*this);
}

double Stopwatch::getElapsedMilliseconds( void )
{
    struct timeval now;
    double seconds;
    double u_seconds;

    if (is_running_)
    {
        if (gettimeofday(&now, NULL))
        {
            throw std::runtime_error(GETTIME_ERR_MSG);
        }
    }
    else
    {
        now = stop_time_;
    }

    seconds = difftime(now.tv_sec, start_time_.tv_sec);
    u_seconds = static_cast<double>(now.tv_usec - start_time_.tv_usec);

    return ((seconds * 1000) + (u_seconds / 1000));
}

bool Stopwatch::getIsRunning( void ) const
{
    return (is_running_);
}

void Stopwatch::start( void )
{
    is_running_ = true;
}

void Stopwatch::reset( void )
{
    is_running_ = false;
    if (gettimeofday(&start_time_, NULL))
    {
        throw std::runtime_error(GETTIME_ERR_MSG);
    }
    stop_time_ = start_time_;
}

void Stopwatch::restart( void )
{
    try
    {
        reset();
    }
    catch(const std::exception& e)
    {
        throw;
    }
    start();
}
