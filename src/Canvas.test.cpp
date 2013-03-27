/*
 * Copyright 2012, 2013 Esrille Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>

#include "CanvasGL.h"
#include "Test.util.h"

void reshape(int w, int h);

Canvas canvas;
Canvas canvasSub;

void render(int w, int h, int s = 50)
{
    glDisable(GL_TEXTURE_2D);

    reshape(w, h);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    unsigned color = 0xff808080;
    glColor4ub(color >> 16, color >> 8, color, color >> 24);
    glLineWidth(1);
    glBegin(GL_LINES);
    for (int x = 0; x <= w; x += s) {
        glVertex2i(x, 0);
        glVertex2i(x, h);
    }
    for (int y = 0; y <= h; y += s) {
        glVertex2i(0, y);
        glVertex2i(w, y);
    }
    glEnd();

    glFlush();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    canvas.render(816, 1056);
    glPushMatrix();
    glTranslatef(50, 50, 0);
    canvasSub.alphaBlend(512, 512, 0.5f);
    glPopMatrix();

    glutSwapBuffers();  // This would block until the sync happens
}

int main(int argc, char* argv[])
{
    init(&argc, argv);

    glutDisplayFunc(myDisplay);

    canvas.setup(816, 1056);
    canvas.beginRender(0xffff0000);
    render(816, 1056);
    glPushMatrix();
        glTranslatef(50, 50, 0);
        canvasSub.setup(512, 512);
        canvasSub.beginRender(0xffffffff);
        render(512, 512, 10);
        canvasSub.endRender();
    glPopMatrix();
    canvas.endRender();


    glColor4ub(255, 255, 255, 255);
    glutMainLoop();

    canvas.shutdown();
}
