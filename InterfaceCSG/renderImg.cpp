#include "renderImg.h"
#include <QMouseEvent>
#include <iostream>

//#include "imgGradient.h"
//#include "boundingbox.h"
#include <limits>
#include "Vec2V.h"


RenderImg::RenderImg(BoundingBox& box, QWidget *parent ):
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
    m_texture(0),
    m_widthTex(0),
    m_heightTex(0),
    m_ptrTex(NULL),
    m_imgGrey(1024,1024),
    m_drawSobel(false),
    m_BBdraw(false),
    pointSource(),
    m_BB(box)
  // Autres Inits
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(20);
    connect(m_timer, SIGNAL(timeout()),this, SLOT(animate()));

    // Init Vecteur, et point Source
    pointSize = 3.;
    m_nbrParticule = 100;
    tabVec = new Vec2V[m_nbrParticule]();
    m_particules = new Particule[m_nbrParticule]();
    double debut = 0;
    Vec2d pos;
    //Init du tableau de particules
    for(int i=0;i<m_nbrParticule;i++){
        debut = debut +10;
        pos = { debut,10 };
        m_particules[i].setPos_courant(pos);
        m_particules[i].setDateActuel(100);
    }
    //Init texture parametre
    m_widthTex=m_imgGrey.getWidth();
    m_heightTex=m_imgGrey.getHeight();
    m_ptrTex=m_imgGrey.getData();
}


void RenderImg::loadTexture(const std::string& filename)
{
    // VOTRE CODE ICI
    m_imgGrey.loadToPGM(filename);
    m_widthTex=m_imgGrey.getWidth();
    m_heightTex=m_imgGrey.getHeight();
    m_ptrTex=m_imgGrey.getData();

    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
    glBindTexture(GL_TEXTURE_2D, 0);
}

//On fait un save juste au cas ou ca peut servir
void RenderImg::saveTexture(const std::string& filename){
    m_imgGrey.saveToPGM(filename);
}

void RenderImg::updateDataTexture()
{
    m_ptrTex = m_imgGrey.getData();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,m_widthTex, m_heightTex, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
    glBindTexture(GL_TEXTURE_2D, 0);
    updateGL();
}


Image2Grey& RenderImg::getImg(){
    return this->m_imgGrey;
}

unsigned int RenderImg::getWidth()
{
    return m_widthTex;
}

unsigned int RenderImg::getHeight()
{
    return m_heightTex;
}


RenderImg::~RenderImg()
{
    glDeleteTextures(1, &m_texture);
    m_texture = 0;
}

void RenderImg::initializeGL()
{
    glClearColor(0.0f,0.0f,0.4f,0.0f);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
    glBindTexture(GL_TEXTURE_2D, 0);


}

void RenderImg::paintGL()
{
    glEnable(GL_POINT_SMOOTH);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex2f( -1,1);
    glTexCoord2f(0,1);
    glVertex2f(-1,-1);
    glTexCoord2f(1,1);
    glVertex2f( 1,-1);
    glTexCoord2f(1,0);
    glVertex2f( 1,1);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);

    // for debugging
    if (m_drawSobel)
        drawSobel();

    if (m_BBdraw)
        drawBB(m_BB);

    glPointSize(pointSize);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for (int i = 0; i < m_nbrParticule; i++ )
    {
        glVertex2fv(tabVec[i].get_ptr());
        glVertex2d(xImg2GL(m_particules[i].getPos_courant()[0]),yImg2GL(m_particules[i].getPos_courant()[1]));
    }
    glEnd();
}

void RenderImg::resizeGL(int width, int height)
{
    m_winW = width;
    m_winH = height;
    int side = qMin(width, height);
    m_winS = side;
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    update();
}

void RenderImg::coordInTexture(QMouseEvent *event, int& x, int& y)
{
    if (m_winS == m_winW)
    {
        x = (float(event->x())/m_winW)*m_widthTex;
        y = (float(event->y()-(m_winH-m_winS)/2)/m_winH)*m_heightTex;
    }
    else
    {
        x = (float(event->x()-(m_winW-m_winS)/2)/m_winH)*m_widthTex;
        y = (float(event->y())/m_winH)*m_heightTex;
    }
}


void RenderImg::mousePressEvent(QMouseEvent *event)
{
    int x,y;
    coordInTexture(event, x, y);
    m_lastPos.setX(x);
    m_lastPos.setY(y);

    std::cout << "Mouse-press in widget"<< event->x() << " / "<< event->y() << std::endl;
    std::cout << " =>  position in texture "<< x << " / "<< y << std::endl;

    if (m_state_modifier & Qt::ShiftModifier)
        std::cout << "     with Shift" << std::endl;
    if (m_state_modifier & Qt::ControlModifier)
        std::cout << "     with Ctrl" << std::endl;



    paintGL();

    glPointSize(4.0f);
    glColor3f(1.0f,0,0);
    glBegin(GL_POINTS);

    unsigned int nbp = m_nbrParticule;// VOTRE CODE ICI : nombre de particules
    for (unsigned int i = 0; i < nbp; i++ )
    {
        // here get back position of each particle in ptPos
        glVertex2f(2.0f*m_lastPos.x()/m_widthTex-1.0f, -2.0f*m_lastPos.y()/m_heightTex+1.0f);
    }
    glEnd();

    swapBuffers();
}


void RenderImg::mouseReleaseEvent(QMouseEvent *event)
{
    int x,y;
    coordInTexture(event, x, y);
    m_lastPos.setX(x);
    m_lastPos.setY(y);

    std::cout << " RELEASE in texture "<< x << " / "<< y << std::endl;

}

void RenderImg::keyPressEvent(QKeyEvent* event)
{
    m_state_modifier = event->modifiers();
    double debut = 0;
    Vec2d pos = { 0,0 };
    switch(event->key())
    {
        case 'A':

            break;
        case 'E':
            m_timer->start();
            break;
        case 'S':
            m_timer->stop();
            // ??
            break;
        case 'P':
            if (m_timer->isActive())
                m_timer->stop();
            else
                m_timer->start();
            break;
    }
    update();

}

void RenderImg::animate()
{
    for(int i=0; i<m_nbrParticule ; i++){
        tabVec[i].avance(pointSource[0],pointSource[1]);
        m_particules[i].computeVitFuture();
        m_particules[i].computePosFuture();
        m_particules[i].changePosition();
        if(m_particules[i].getPos_courant()[0]>getWidth() || m_particules[i].getPos_courant()[1]>getHeight()){
            m_particules[i].setVit_courant(-m_particules[i].getVit_courant()/1.25);
        }
    }
    update();
}

void RenderImg::keyReleaseEvent(QKeyEvent* /*event*/)
{
    m_state_modifier = 0;
}


void RenderImg::clean()
{
    unsigned char* ptr=m_ptrTex;

    for (int i=0; i<m_heightTex; ++i)
    {
        for (int j=0; j<m_widthTex; ++j)
        {
            *ptr++ = 0;
        }
    }
}

//TODO
void RenderImg::toggleSobel()
{
    m_drawSobel = !m_drawSobel;
    if (m_drawSobel)
    {
//		m_img = m_img.average(2);
//		m_grad = GradientSobel::gradient33(m_img);
//		m_img.threshold(128);
        updateDataTexture();
    }
    update();
}

//TODO
void RenderImg::drawSobel()
{
    glBegin(GL_LINES);
    for (int j=0; j<m_heightTex; j+=2)
    {
        for (int i=0; i<m_widthTex; i+=2)
        {
            // get value of gradiant
            // Vec2f v = ??

//			if (v*v > 0.001f)
//			{
//				float x = -1.0f + (2.0f*i)/(m_widthTex-1);
//				float y = 1.0f  - (2.0f*j)/(m_heightTex-1);// minus because of GL is bottom to up and image up to boytom
//				v *= 4.0f/m_widthTex;
//				glColor3f(1.0f,1.0f,0.0f);
//				glVertex2f(x,y);
//				glColor3f(1.0f,0.0f,0.0f);
//				glVertex2f(x+v[0],y-v[1]);
//			}
        }
    }
    glEnd();
}


void RenderImg::drawBB(const BoundingBox& bb)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f,0.5f,0.5f);
    glVertex2f( xImg2GL(bb.getMin()[0]), yImg2GL(bb.getMax()[1]) );
    glVertex2f( xImg2GL(bb.getMin()[0]), yImg2GL(bb.getMax()[1]) );
    glVertex2f( xImg2GL(bb.getMax()[0]), yImg2GL(bb.getMax()[1]) );
    glVertex2f( xImg2GL(bb.getMax()[0]), yImg2GL(bb.getMin()[1]) );
    glEnd();
}

//Test de Draw de Primitive
void RenderImg::drawPrimitve(csgNode* node){
    glPointSize(1.);
    glColor3f(1.,1.,1.);
    glBegin(GL_POINTS);
    csgPrimitive *nodePrim = static_cast<csgPrimitive*>(node);
    if(nodePrim->getLabel().compare("disk") == 0){
        std::cout<<"je dessine"<<std::endl;
        csgDisk *nodeDisk = static_cast<csgDisk*>(nodePrim);
        double x = nodeDisk->getCentre()[0];
        double y = nodeDisk->getCentre()[1];
        for(int i=0;i<100;i++){
            x=x+1;
            y=y+1;
            glVertex2d(2.0f*x/m_widthTex-1.0f,-2.0f*y/m_heightTex+1.0f);
        }
    }else if(nodePrim->getLabel().compare("polygon") == 0){
        csgPolygon *nodePoly = static_cast<csgPolygon*>(nodePoly);
    }
    glEnd();
}


