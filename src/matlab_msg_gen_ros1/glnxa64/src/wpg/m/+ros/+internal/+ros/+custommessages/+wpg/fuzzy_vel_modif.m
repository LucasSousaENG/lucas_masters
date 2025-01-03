function [data, info] = fuzzy_vel_modif
%fuzzy_vel_modif gives an empty data for wpg/fuzzy_vel_modif
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'wpg/fuzzy_vel_modif';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.DistanceToObstacle, info.DistanceToObstacle] = ros.internal.ros.messages.ros.default_type('double',1);
[data.DistanceToObjective, info.DistanceToObjective] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Velocity, info.Velocity] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'wpg/fuzzy_vel_modif';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,9);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'distance_to_obstacle';
info.MatPath{8} = 'distance_to_objective';
info.MatPath{9} = 'velocity';
