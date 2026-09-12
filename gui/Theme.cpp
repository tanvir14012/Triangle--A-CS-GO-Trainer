#include "Theme.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;
namespace gui {
void Theme::Apply(Control^ root)
{
    root->Font = gcnew System::Drawing::Font("Segoe UI", 9.0f);
    root->BackColor = Color::FromArgb(45, 45, 48);
    root->ForeColor = Color::Gainsboro;
    auto slider = dynamic_cast<TrackBar^>(root);
    if (slider) {
        slider->AutoSize = false;
        slider->Height = 26;
    }
    for each (Control^ child in root->Controls) {
        // These buttons display user-selected overlay colors.
        if (dynamic_cast<Button^>(child) &&
            (child->Name == "button1" || child->Name == "button2" ||
             child->Name == "button3" || child->Name == "button4")) continue;
        Apply(child);
    }
}
}
