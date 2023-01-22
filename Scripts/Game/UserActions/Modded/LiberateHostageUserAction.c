class LiberateHostageUserAction : ScriptedUserAction
{
	private bool canBeShown = true;
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		Print("start PerformAction");
		
		AIAgent agent = AIAgent.Cast(GetGame().GetWorld().FindEntityByName("Hostage"));	
		AIWaypoint waypoint = AIWaypoint.Cast(GetGame().GetWorld().FindEntityByName("Hostage_WP_GetInBTR_NoDriver"));
 		SCR_AIGroup groupAI = SCR_AIGroup.Cast(agent);
 		groupAI.AddWaypointToGroup(waypoint);

		canBeShown = false;
	}
	
	override bool CanBeShownScript(IEntity user) { return canBeShown; }
	//override bool HasLocalEffectOnlyScript() { return false; };
};