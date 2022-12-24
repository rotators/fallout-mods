/*

    Test with visibile footsteps

*/

#pragma once

#define FID_FOOT_1         (33556338)
#define FID_FOOT_2         (33556339)

#define create_footsteps(crit)   call footsteps(crit)

variable last_step := 0, new_step := 0, step_fid, step_crit;
procedure footsteps(variable step_crit) begin
   new_step := tile_num(step_crit);
   if (last_step != new_step) then begin
      last_step := new_step;

      //debug("get_tile_fid: " + get_tile_fid(dude_tile));
      if (get_tile_fid(tile_num(step_crit)) >= 191 and get_tile_fid(tile_num(step_crit)) <= 198)
         or ((get_tile_fid(tile_num(step_crit)) >= 173) and (get_tile_fid(tile_num(step_crit)) <= 175))
         or (get_tile_fid(tile_num(step_crit)) == 203)
         or ((get_tile_fid(tile_num(step_crit)) >= 205) and (get_tile_fid(tile_num(step_crit)) <= 206))
         or (get_tile_fid(tile_num(step_crit)) == 208)
         or (get_tile_fid(tile_num(step_crit)) == 211)
         or (get_tile_fid(tile_num(step_crit)) == 214)

      then begin
         set_global_var(2000, global_var(2000) + 1);
         Scenery_Creation := create_object_sid(33554866, new_step, elevation(step_crit), SCRIPT_TEST);

         if (step_fid == 0) then begin
            step_fid := 1;
            art_change_fid_num(Scenery_Creation, FID_FOOT_1);
         end
         else begin
            step_fid := 0;
            art_change_fid_num(Scenery_Creation, FID_FOOT_2);
         end
         obj_rotate(Scenery_Creation, get_cur_rot(step_crit));
      end
   end
end