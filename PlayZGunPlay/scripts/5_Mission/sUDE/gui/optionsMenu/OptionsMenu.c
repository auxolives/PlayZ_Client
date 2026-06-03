// Yo simonvic, let me know if you want to add it back <3
// You are praised in our community, it's only an aesthetic choice~
modded class OptionsMenu
{
    override Widget Init()
    {
        Widget layoutRoot = super.Init();
        
        // Yo simonvic, let me know if you want to add it back <3
        // You are praised in our community, it's only an aesthetic choice~
        
        // Since TextWidget.GetText() is undefined in Enforce Script, we identify the sUDE tab
        // by its position. sFramework always adds its tab as the last one during Init.
        if (m_Tabber)
        {
            int sUDEIndex = m_Tabber.GetTabCount() - 1;
            if (sUDEIndex >= 0)
            {
                // Hide the Tab Button (Navigation)
                Widget tabButton = layoutRoot.FindAnyWidget("Tab_Control_" + sUDEIndex);
                if (tabButton)
                {
                    tabButton.Show(false);
                }
                
                // Hide the Tab Content (Settings Pane)
                Widget tabContent = layoutRoot.FindAnyWidget("Tab_" + sUDEIndex);
                if (tabContent)
                {
                    tabContent.Show(false);
                }
            }
        }

        return layoutRoot;
    }
}
