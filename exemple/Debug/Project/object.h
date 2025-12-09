#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object{
    public:
        virtual void start() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif