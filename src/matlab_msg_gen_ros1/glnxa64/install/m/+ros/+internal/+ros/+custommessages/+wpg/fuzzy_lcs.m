function [data, info] = fuzzy_lcs
%fuzzy_lcs gives an empty data for wpg/fuzzy_lcs
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'wpg/fuzzy_lcs';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.KP, info.KP] = ros.internal.ros.messages.ros.default_type('double',1);
[data.KI, info.KI] = ros.internal.ros.messages.ros.default_type('double',1);
[data.KD, info.KD] = ros.internal.ros.messages.ros.default_type('double',1);
[data.ObjVel, info.ObjVel] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'wpg/fuzzy_lcs';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,10);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'kP';
info.MatPath{8} = 'kI';
info.MatPath{9} = 'kD';
info.MatPath{10} = 'obj_vel';
