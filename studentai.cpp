
#include "micromouseserver.h"
#include <ostream>
#include <stack>

void microMouseServer::studentAI()
{

  // Initialize any variables needed for the AI
    QPoint newPos;


    std::stack<QPoint> visited;
    int targetX = 1, targetY = 10;
    bool visitedPoints[MAZE_WIDTH][MAZE_HEIGHT] = { {false} };

    // Push the starting point onto the stack
    visited.push(newPos);
    visitedPoints[newPos.x()][newPos.y()] = true;
    while (true)
    {
        // Check if the mouse has reached the target coordinates
        if (newPos.x() == targetX && newPos.y() == targetY)
        {
            foundFinish();
            break;
        }

        // Try moving forward
        if (!isWallForward())
        {
            moveForward();
            newPos.setX(this->maze->mouseX());
            newPos.setY(this->maze->mouseY());
            if (!visitedPoints[newPos.x()][newPos.y()])
                {
              //  newPos.setX(this->maze->mouseX());
              //  newPos.setY(this->maze->mouseY());
                visited.push(newPos);
                visitedPoints[newPos.x()][newPos.y()] = true;
                }
            }
        else
        {
            // If there is a wall in front, try turning right
            if (!isWallRight())
            {
                turnRight();
                moveForward();
                newPos.setX(this->maze->mouseX());
                newPos.setY(this->maze->mouseY());
                if (!visitedPoints[newPos.x()][newPos.y()])
                    {
                  //  newPos.setX(this->maze->mouseX());
                  //  newPos.setY(this->maze->mouseY());
                    visited.push(newPos);
                    visitedPoints[newPos.x()][newPos.y()] = true;
                    }
            }
            else
            {
                // If there is a wall to the right, try turning left
                if (!isWallLeft())
                {
                    turnLeft();
                    moveForward();
                    newPos.setX(this->maze->mouseX());
                    newPos.setY(this->maze->mouseY());
                    if (!visitedPoints[newPos.x()][newPos.y()])
                        {
                    //    newPos.setX(this->maze->mouseX());
                     //   newPos.setY(this->maze->mouseY());
                        visited.push(newPos);
                        visitedPoints[newPos.x()][newPos.y()] = true;
                        }
                }
                else
                {
                    // If there are walls in all directions, backtrack
                    visited.pop();
                    if (visited.empty())
                    {
                        break;
                    }
                    newPos = visited.top();
                  /*  turnRight();
                    turnRight();

                    if (!isWallForward())
                    {
                        moveForward();
                        newPos.setX(this->maze->mouseX());
                        newPos.setY(this->maze->mouseY());
                        visited.push(newPos);
                        visitedPoints[newPos.x()][newPos.y()] = true;
                    }
                    else
                    {
                        break;
                    } */

            }
        }
    }

}
}
