function [data, info] = defuzzy_lcs
%defuzzy_lcs gives an empty data for wpg/defuzzy_lcs
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'wpg/defuzzy_lcs';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.NewP, info.NewP] = ros.internal.ros.messages.ros.default_type('double',1);
[data.NewI, info.NewI] = ros.internal.ros.messages.ros.default_type('double',1);
[data.NewD, info.NewD] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'wpg/defuzzy_lcs';
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
info.MatPath{7} = 'New_P';
info.MatPath{8} = 'New_I';
info.MatPath{9} = 'New_D';
