function [data, info] = fuzzy
%fuzzy gives an empty data for wpg/fuzzy
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'wpg/fuzzy';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.Error, info.Error] = ros.internal.ros.messages.ros.default_type('double',1);
[data.DError, info.DError] = ros.internal.ros.messages.ros.default_type('double',1);
[data.PVal, info.PVal] = ros.internal.ros.messages.ros.default_type('double',1);
[data.IVal, info.IVal] = ros.internal.ros.messages.ros.default_type('double',1);
[data.DVal, info.DVal] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'wpg/fuzzy';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,11);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'Error';
info.MatPath{8} = 'D_Error';
info.MatPath{9} = 'P_val';
info.MatPath{10} = 'I_val';
info.MatPath{11} = 'D_val';
