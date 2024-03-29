#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QKeyEvent>

#include "renderImg.h"
#include "csgNode.h"
#include "csgPrimitive.h"
#include "csgTree.h"
#include "csgOperation.h"
#include "CsgPolygon.h"
#include "CsgDisk.h"

#include <map>

namespace Ui {
class MainWindow;
}


/**
 * @brief TextEdit Widget for CSG Graph
 */
class GraphTextEdit: public QPlainTextEdit
{
protected:
    char m_pressed;
public:

    GraphTextEdit();

    void keyPressEvent(QKeyEvent* event) { m_pressed = char(event->key()+32); }

    void keyReleaseEvent(QKeyEvent* /*event*/) { m_pressed = char(0); }

    char pressed() const { return m_pressed; }
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    RenderImg* m_render;

protected:
    /// current selected node
    csgNode* m_currentNode;

    /// current primitive (could be NULL)
    csgPrimitive * m_prim;

    /// current operation (could be NULL)
    csgOperation * m_oper;

    /// the CSG tree
    csgTree m_tree;

    /// Bounding Box to draw
    BoundingBox m_bb;

    /// widget for ascii art grapg drawing
    GraphTextEdit* m_graphTextEdit;

    /// current transfo matrix for storing current primitive matrix
    Matrix33d m_transfo;

    std::vector<Matrix33d> m_transfos;
    std::vector<csgPrimitive*> m_prims;
    Vec2d m_centerSelection;

    /// just to avoid ping-pong signal
    bool m_stopSignal;

    /// current center of current node
    Vec2d m_stored_center;

    void updateTextGraph();

    void closeEvent(QCloseEvent *event);

    /// transfo has changed from interface
    void transfoChanged();

    void resetTransfoWidgets();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawTree();

public slots:
    void createPrimtive();
    void createOperation();
    void applyTransfo();
    void resetTransfo();
    void transfoSliderChanged();
    void transfoSpinChanged();
    void loadImage();
    void saveImage();
    void drawSobel();
    void loadCSG();
    void saveCSG();
    void appendCSG();
    void clearCSG();
    void swapLRRoot();
    void unjoinRoot();
    void clone();
    void updateTreeRender();
    void currentNodeChanged(int id);
    void nodeTextSelected(bool);


};

#endif // MAINWINDOW_H
