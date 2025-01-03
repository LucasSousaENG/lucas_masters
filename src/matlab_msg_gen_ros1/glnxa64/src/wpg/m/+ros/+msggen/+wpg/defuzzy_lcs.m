
classdef defuzzy_lcs < ros.Message
    %defuzzy_lcs MATLAB implementation of wpg/defuzzy_lcs
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'wpg/defuzzy_lcs' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '5018cc07f3c892cd87cba9a4e4753da2' % The MD5 Checksum of the message definition
        PropertyList = { 'Header' 'NewP' 'NewI' 'NewD' } % List of non-constant message properties
        ROSPropertyList = { 'header' 'New_P' 'New_I' 'New_D' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Header' ...
            '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Header
        NewP
        NewI
        NewD
    end
    methods
        function set.Header(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Header'};
            validateattributes(val, validClasses, validAttributes, 'defuzzy_lcs', 'Header')
            obj.Header = val;
        end
        function set.NewP(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'defuzzy_lcs', 'NewP');
            obj.NewP = double(val);
        end
        function set.NewI(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'defuzzy_lcs', 'NewI');
            obj.NewI = double(val);
        end
        function set.NewD(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'defuzzy_lcs', 'NewD');
            obj.NewD = double(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.wpg.defuzzy_lcs.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.wpg.defuzzy_lcs(strObj);
        end
    end
end
