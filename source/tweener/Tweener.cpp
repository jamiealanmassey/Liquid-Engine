#include "Tweener.h"
#include "../utilities/DeltaTime.h"

namespace liquid {
namespace tweener {

    Tweener::Tweener() :
        ITweener()
    {
        mElapsed = 0.0f;
        mInitial = 0.0f;
        mTarget = 0.0f;
        mDuration = 0.0f;
        mValue = 0.0f;
        mUpdateFunc = nullptr;
    }

    Tweener::Tweener(float value, float target, float duration, EasingFunction easingFunc) :
        ITweener()
    {
        mElapsed = 0;
        mInitial = value;
        mTarget = target;
        mDuration = duration;
        mValue = value;
        mEasingFunc = easingFunc;
        mUpdateFunc = nullptr;
    }

    Tweener::Tweener(float value, float target, float duration, EasingFunction easingFunc, UpdateFunc updateFunc) :
        ITweener()
    {
        mElapsed = 0;
        mInitial = value;
        mTarget = target;
        mDuration = duration;
        mValue = 0.0;
        mEasingFunc = easingFunc;
        mUpdateFunc = updateFunc;
    }

    Tweener::~Tweener()
    {}

    float Tweener::update()
    {
        float dt = utilities::DELTA;
        if (mElapsed >= mDuration)
            return dt;

        mValue = calculateValue();
        mElapsed += dt;

        if (mUpdateFunc != nullptr)
            mUpdateFunc(mValue);

        return dt;
    }

    //virtual ITweener* duplicate() override;

    bool Tweener::isFinished()
    {
        if (mElapsed >= mDuration)
        {
            finished();
            return true;
        }

        return false;
    }

    void Tweener::reset()
    {
        mElapsed = 0.0f;
        mValue = mInitial;
    }

    void Tweener::setInitial(float value)
    {
        mInitial = value;
    }

    void Tweener::setTarget(float value)
    {
        mTarget = value;
    }

    void Tweener::setDuration(float value)
    {
        mDuration = value;
    }

    void Tweener::setUpdateFunc(UpdateFunc func)
    {
        mUpdateFunc = func;
    }

    void Tweener::setEasingFunc(EasingFunction func)
    {
        mEasingFunc = func;
    }

    float Tweener::calculateValue()
    {
        float x = mEasingFunc.ease(mElapsed / mDuration);
        float r = mInitial + x * (mTarget - mInitial);
        return r;
    }

    float Tweener::getValue()
    {
        return mValue;
    }

    float Tweener::getInitial() const
    {
        return mInitial;
    }

    float Tweener::getTarget() const
    {
        return mTarget;
    }

    float Tweener::getElapsed() const
    {
        return mElapsed;
    }

    float Tweener::getDuration() const
    {
        return mDuration;
    }

}}
