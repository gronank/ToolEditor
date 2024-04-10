#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui-node-editor/imgui_node_editor.h>
#include <vector>
#include <algorithm>
#include <iostream>
namespace ed = ax::NodeEditor;

struct LinkInfo
{
    ed::LinkId Id;
    ed::PinId  InputId;
    ed::PinId  OutputId;
};

struct Pin
{

};

struct Node
{
    std::string name;
    ed::NodeId nodeId;
    ed::PinId  inPinId;
    ed::PinId  outPinId;
};

Node CreateNode(std::string&& name)
{
    static uintptr_t uniqueId = 0;

    return Node{ std::move(name), uniqueId++, uniqueId++, uniqueId++ };
}

struct AppState
{
    ed::EditorContext* editorContext;
    bool FirstFrame = true;
    std::vector<LinkInfo> Links;
    std::vector<Node> Nodes;
    size_t NextLinkId;
};

void OnStart(AppState& state)
{
    ed::Config config;
    config.SettingsFile = "Simple.json";
    state.editorContext = ed::CreateEditor(&config);
    state.Nodes.push_back(CreateNode("MyNode"));
}

void ImGuiEx_BeginColumn()
{
    ImGui::BeginGroup();
}

void ImGuiEx_NextColumn()
{
    ImGui::EndGroup();
    ImGui::SameLine();
    ImGui::BeginGroup();
}

void ImGuiEx_EndColumn()
{
    ImGui::EndGroup();
}

void drawNode(const Node& node)
{
    const auto    topRoundCornersFlags = ImDrawFlags_RoundCornersTop;
    const auto bottomRoundCornersFlags = ImDrawFlags_RoundCornersBottom | ImDrawFlags_RoundCornersTop;

    ed::BeginNode(node.nodeId);
    ImGui::Text(node.name.c_str());
    auto drawList = ImGui::GetWindowDrawList();


    ed::PushStyleVar(ed::StyleVar_PinArrowSize, 10.0f);
    ed::PushStyleVar(ed::StyleVar_PinArrowWidth, 10.0f);
    ed::PushStyleVar(ed::StyleVar_PinCorners, ImDrawFlags_RoundCornersBottom);
    ed::BeginPin(node.inPinId, ed::PinKind::Input);
    ImGui::Dummy(ImVec2(5,5));
    auto min = ImGui::GetItemRectMin();
    auto max = ImGui::GetItemRectMax();
    drawList->AddRectFilled(min, max,
        IM_COL32(0, 255, 0, 255), 4.0f, bottomRoundCornersFlags);
    //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    /*drawList->AddRect(min + ImVec2(0, 1), inputsRect.GetBR(),
        IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, bottomRoundCornersFlags);
        */
    ed::EndPin();
    ed::PopStyleVar(3);
    


    

    ImGui::SameLine();

    ed::BeginPin(node.outPinId, ed::PinKind::Output);
    ImGui::Text("Out ->");
    ed::EndPin();

    ed::EndNode();
}

void OnFrame(AppState& state, ImGuiIO& io)
{
    
        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("FPS: %.2f (%.2gms)", io.Framerate, io.Framerate ? 1000.0f / io.Framerate : 0.0f);

        ImGui::Separator();
        ed::SetCurrentEditor(state.editorContext);

        // Start interaction with editor.
        ed::Begin("My Editor", ImVec2(0.0, 0.0f));

        int uniqueId = 1;

        //
        // 1) Commit known data to editor
        //

        // Submit Node A
        ed::NodeId nodeA_Id = uniqueId++;
        ed::PinId  nodeA_InputPinId = uniqueId++;
        ed::PinId  nodeA_OutputPinId = uniqueId++;

        
            
        ed::PushStyleColor(ed::StyleColor_NodeBg, ImColor(128, 0, 0, 200));
        ed::PushStyleColor(ed::StyleColor_NodeBorder, ImColor(32, 32, 32, 200));
        ed::PushStyleColor(ed::StyleColor_PinRect, ImColor(60, 180, 255, 150));
        ed::PushStyleColor(ed::StyleColor_PinRectBorder, ImColor(60, 180, 255, 150));
        ed::PushStyleVar(ed::StyleVar_NodePadding, ImVec4(0, 0, 0, 0));
        ed::PushStyleVar(ed::StyleVar_NodeRounding, 1.0);
        ed::PushStyleVar(ed::StyleVar_SourceDirection, ImVec2(0.0f, 1.0f));
        ed::PushStyleVar(ed::StyleVar_TargetDirection, ImVec2(0.0f, -1.0f));
        ed::PushStyleVar(ed::StyleVar_LinkStrength, 0.0f);
        //ed::PushStyleVar(ed::StyleVar_PinBorderWidth, 1.0f);
        //ed::PushStyleVar(ed::StyleVar_PinRadius, 5.0f);


        for (const auto& node : state.Nodes)
        {
            if (state.FirstFrame)
                ed::SetNodePosition(node.nodeId, ImVec2(10, 10));
            drawNode(node);
        }




        // Submit Node B
        ed::NodeId nodeB_Id = uniqueId++;
        ed::PinId  nodeB_InputPinId1 = uniqueId++;
        ed::PinId  nodeB_InputPinId2 = uniqueId++;
        ed::PinId  nodeB_OutputPinId = uniqueId++;

        if (state.FirstFrame)
            ed::SetNodePosition(nodeB_Id, ImVec2(210, 60));
        ed::BeginNode(nodeB_Id);
        ImGui::Text("Node B");
        ImGuiEx_BeginColumn();
        ed::BeginPin(nodeB_InputPinId1, ed::PinKind::Input);
        ed::EndPin();
        ed::BeginPin(nodeB_InputPinId2, ed::PinKind::Input);
        ImGui::Text("-> In2");
        ed::EndPin();
        ImGuiEx_NextColumn();
        ed::BeginPin(nodeB_OutputPinId, ed::PinKind::Output);
        ImGui::Text("Out ->");
        ed::EndPin();
        ImGuiEx_EndColumn();
        ed::EndNode();

        // Submit Links
        for (auto& linkInfo : state.Links)
            ed::Link(linkInfo.Id, linkInfo.InputId, linkInfo.OutputId);

        //
        // 2) Handle interactions
        //

        // Handle creation action, returns true if editor want to create new object (node or link)
        if (ed::BeginCreate())
        {
            ed::PinId inputPinId, outputPinId;
            if (ed::QueryNewNode(&outputPinId))
            {
                if (ed::AcceptNewItem())
                {
                    std::cout << "Query new node\n";
                }
            }
            if (ed::QueryNewLink(&inputPinId, &outputPinId))
            {
                
                // QueryNewLink returns true if editor want to create new link between pins.
                //
                // Link can be created only for two valid pins, it is up to you to
                // validate if connection make sense. Editor is happy to make any.
                //
                // Link always goes from input to output. User may choose to drag
                // link from output pin or input pin. This determine which pin ids
                // are valid and which are not:
                //   * input valid, output invalid - user started to drag new ling from input pin
                //   * input invalid, output valid - user started to drag new ling from output pin
                //   * input valid, output valid   - user dragged link over other pin, can be validated

                if (ed::AcceptNewItem())
                {
                    std::cout << "Query new link\n";
                    if (inputPinId && outputPinId) // both are valid, let's accept link
                    {
                        // ed::AcceptNewItem() return true when user release mouse button.

                            // Since we accepted new link, lets add one to our list of links.
                        state.Links.push_back({ ed::LinkId(state.NextLinkId++), inputPinId, outputPinId });

                        // Draw new link.
                        ed::Link(state.Links.back().Id, state.Links.back().InputId, state.Links.back().OutputId);
                    }

                    // You may choose to reject connection between these nodes
                    // by calling ed::RejectNewItem(). This will allow editor to give
                    // visual feedback by changing link thickness and color.
                }
                

            }
        }
        ed::EndCreate(); // Wraps up object creation action handling.


        // Handle deletion action
        if (ed::BeginDelete())
        {
            ed::NodeId deletedNodeId;
            while (ed::QueryDeletedNode(&deletedNodeId))
            {
                if (ed::AcceptDeletedItem())
                {

                }
            }
            // There may be many links marked for deletion, let's loop over them.
            ed::LinkId deletedLinkId;
            while (ed::QueryDeletedLink(&deletedLinkId))
            {
                // If you agree that link can be deleted, accept deletion.
                if (ed::AcceptDeletedItem())
                {
                    // Then remove link from your data.
                    auto it = std::ranges::find(state.Links, deletedLinkId, [](const auto& link) {return link.Id; });
                    state.Links.erase(it);
                }

                // You may reject link deletion by calling:
                // ed::RejectDeletedItem();
            }
        }
        ed::EndDelete(); // Wrap up deletion action



        // End of interaction with editor.
        ed::End();

        if (state.FirstFrame)
            ed::NavigateToContent(0.0f);

        ed::SetCurrentEditor(nullptr);

        state.FirstFrame = false;

        ed::SetCurrentEditor(nullptr);
        ImGui::End();
    
}

void OnStop(AppState& state)
{
    ed::DestroyEditor(state.editorContext);
}